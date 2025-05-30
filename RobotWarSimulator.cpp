/**********|**********|**********|
Program: RobotWarSimulator.cpp
Course: OOPDS
Trimester: 2510
Name: Sharveeny
ID: 242UC241DD
Lecture Section: TC1L
Tutorial Section: TT2L
Email: SHARVEENY.KALAI.KUMAR@student.mmu.edu.my
Phone: 0174081106
**********|**********|**********/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "robot.h"
#include "scoutbot.h"
#include "firerobot.h"
#include "reconrobot.h"
using namespace std;

int M, N, MAX_STEPS;
class Robot; // Forward declaration
vector<vector<char>> battlefield;
vector<Robot*> robots;

Position findRandomEmptyPosition(int rows, int cols, const vector<vector<char>>& battlefield) {
    Position pos;
    do {
        pos.robotPositionX = rand() % rows;
        pos.robotPositionY = rand() % cols;
    } while (battlefield[pos.robotPositionX][pos.robotPositionY] != '.');
    return pos;
}

class GenericRobot : public Robot {
public:
    GenericRobot(string n, int xPos, int yPos)
        : Robot(n, xPos, yPos, N, M) {
        battlefield[xPos][yPos] = name[0];
    }
    void think() override {}
    void look() override { cout << name << " looks around.\n"; }
    void move() override {
        int dx = rand() % 3 - 1, dy = rand() % 3 - 1;
        int newX = pos.robotPositionX + dx, newY = pos.robotPositionY + dy;
        if (newX >= 0 && newX < M && newY >= 0 && newY < N && battlefield[newX][newY] == '.') {
            battlefield[pos.robotPositionX][pos.robotPositionY] = '.';
            pos.robotPositionX = newX;
            pos.robotPositionY = newY;
            battlefield[newX][newY] = name[0];
            cout << name << " moved to (" << newX << "," << newY << ").\n";
        }
    }
    void fire() override {
        if (shells <= 0) { handleDeath(); return; }
        int dx = rand() % 3 - 1, dy = rand() % 3 - 1;
        int tx = pos.robotPositionX + dx, ty = pos.robotPositionY + dy;
        if ((dx != 0 || dy != 0) && tx >= 0 && tx < M && ty >= 0 && ty < N) {
            for (Robot* r : robots) {
                if (r->isLives() && r != this &&
                    tx == r->getPosition().robotPositionX &&
                    ty == r->getPosition().robotPositionY) {
                    if ((rand() % 100) < 70) {
                        r->takeDamage(100);
                        cout << name << " fired and hit " << r->getName() << "!\n";
                    } else {
                        cout << name << " fired and missed.\n";
                    }
                    break;
                }
            }
        }
        shells--;
    }
    void handleDeath() {
        battlefield[pos.robotPositionX][pos.robotPositionY] = '.';
        lives--;
        if (lives > 0) {
            cout << name << " is respawning...\n";
            Position newPos = findRandomEmptyPosition(M, N, battlefield);
            pos = newPos; health = 100; shells = 10;
            battlefield[newPos.robotPositionX][newPos.robotPositionY] = name[0];
        } else {
            alive = false;
            cout << name << " has been destroyed.\n";
        }
    }
    void displayAction() override {
        cout << name << " is taking action.\n";
    }
    bool canUpgrade() const override { return false; }
    void upgrade(const string& upgradeType) override {
        cout << name << " does not support upgrades.\n";
    }
};

void displayBattlefield() {
    cout << "\nBattlefield:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << battlefield[i][j] << ' ';
        }
        cout << endl;
    }
}

void simulate() {
    for (int step = 0; step < MAX_STEPS; ++step) {
        cout << "\n--- Turn " << step + 1 << " ---\n";
        displayBattlefield();

        for (Robot* r : robots) {
            if (r->isLives()) {
                r->displayAction();
                r->think();
                r->look();
                r->fire();
                r->move();
            }
        }

        int aliveCount = 0;
        for (Robot* r : robots) if (r->isLives()) aliveCount++;
        if (aliveCount <= 1) break;
    }
    cout << "\nSimulation Ended.\n";
}

int main() {
    srand(time(0));
    ifstream configFile("input.txt");
    if (!configFile) {
        cerr << "Failed to open input.txt. Please make sure the file exists.\n";
        return 1;
    }

    string line;
    int robotCount = 0;

    while (getline(configFile, line)) {
        istringstream iss(line);
        string label;

        if (line.find("M by N") != string::npos) {
            string dummy;
            iss >> dummy >> dummy >> M >> N;
        } else if (line.find("steps:") != string::npos) {
            iss >> label >> MAX_STEPS;
        } else if (line.find("robots:") != string::npos) {
            iss >> label >> robotCount;
        } else if (!line.empty() && isalpha(line[0])) {
            string type, name, xStr, yStr;
            iss >> type >> name >> xStr >> yStr;

            int x = (xStr == "random") ? rand() % M : stoi(xStr);
            int y = (yStr == "random") ? rand() % N : stoi(yStr);

            if (type == "GenericRobot") {
                robots.push_back(new GenericRobot(name, x, y));
            } else if (type == "FireRobot") {
                robots.push_back(new FireRobot(name, x, y, N, M));
            } else if (type == "ScoutBot") {
                robots.push_back(new ScoutBot(name, x, y, N, M));
            } else if (type == "ReconRobot") {
                robots.push_back(new ReconRobot(name, x, y, N, M));
            } else {
                cerr << "Unknown robot type: " << type << endl;
            }

            cout << "[DEBUG] Added robot: " << name << " (" << type << ") at (" << x << ", " << y << ")\n";
        }
    }

    battlefield = vector<vector<char>>(M, vector<char>(N, '.'));

    for (Robot* r : robots) {
        Position p = r->getPosition();
        battlefield[p.robotPositionX][p.robotPositionY] = r->getName()[0];
    }

    simulate();

    for (Robot* r : robots) delete r;
    return 0;
}
