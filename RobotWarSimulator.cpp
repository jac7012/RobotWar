#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Robot.h"
using namespace std;

const int M = 20; // Rows
const int N = 40; // Columns
const int MAX_STEPS = 100;

class Robot;
vector<vector<char>> battlefield(M, vector<char>(N, '.'));
vector<Robot*> robots;

class GenericRobot : public Robot {
public:
    GenericRobot(string n, int xPos, int yPos) : Robot(n, xPos, yPos) {
        battlefield[x][y] = name[0];
    }

    void think() override {}

    void look() override {
        cout << name << " looks around.\n";
    }

    void move() override {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        int newX = x + dx, newY = y + dy;
        if (newX >= 0 && newX < M && newY >= 0 && newY < N && battlefield[newX][newY] == '.') {
            battlefield[x][y] = '.';
            x = newX; y = newY;
            battlefield[x][y] = name[0];
            cout << name << " moved to (" << x << "," << y << ").\n";
        }
    }

    void fire() override {
        if (shells <= 0) {
            destroy();
            battlefield[x][y] = '.';
            cout << name << " ran out of shells and self-destructed.\n";
            return;
        }
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        int tx = x + dx;
        int ty = y + dy;
        if ((dx != 0 || dy != 0) && tx >= 0 && tx < M && ty >= 0 && ty < N) {
            for (Robot* r : robots) {
                if (r->alive() && r != this && tx == r->getX() && ty == r->getY()) {
                    if ((rand() % 100) < 70) {
                        r->destroy();
                        battlefield[tx][ty] = '.';
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

    void displayAction() override {
        cout << name << " is taking action.\n";
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
            if (r->alive()) {
                r->displayAction();
                r->think();
                r->look();
                r->fire();
                r->move();
            }
        }

        int aliveCount = 0;
        for (Robot* r : robots) if (r->alive()) aliveCount++;
        if (aliveCount <= 1) break;
    }
    cout << "\nSimulation Ended.\n";
}

int main() {
    srand(time(0));
    robots.push_back(new GenericRobot("Kidd", 3, 6));
    robots.push_back(new GenericRobot("Jet", 12, 1));
    robots.push_back(new GenericRobot("Alpha", 15, 20));
    robots.push_back(new GenericRobot("Beta", 10, 25));
    robots.push_back(new GenericRobot("Star", rand() % M, rand() % N));

    simulate();

    for (Robot* r : robots) delete r;
    return 0;
}
