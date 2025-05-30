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
#include "newrobot.h" // Assumes Robot base class and Position struct are defined here
using namespace std;

// Battlefield dimensions and simulation step count
// These will be set from input.txt file
int M; // Number of rows
int N; // Number of columns
int MAX_STEPS; // Maximum number of simulation turns

class Robot; // Forward declaration of Robot class

// Global battlefield and robot list
vector<vector<char>> battlefield;
vector<Robot*> robots;

// Function to find a random empty location in the battlefield
Position findRandomEmptyPosition(int rows, int cols, const vector<vector<char>>& battlefield) {
    Position pos;
    do {
        pos.robotPositionX = rand() % rows;
        pos.robotPositionY = rand() % cols;
    } while (battlefield[pos.robotPositionX][pos.robotPositionY] != '.');
    return pos;
}

// GenericRobot class inheriting from Robot
class GenericRobot : public Robot {
public:
    GenericRobot(string n, int xPos, int yPos)
        : Robot(n, xPos, yPos, N, M) {
        // Place robot on battlefield using the first letter of its name
        battlefield[xPos][yPos] = name[0];
    }

    void think() override {
        // Empty for now – can be used for decision logic
    }

    void look() override {
        cout << name << " looks around.\n";
    }

    void move() override {
        // Attempt to move to a random neighboring cell
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        int newX = pos.robotPositionX + dx;
        int newY = pos.robotPositionY + dy;

        if (newX >= 0 && newX < M && newY >= 0 && newY < N && battlefield[newX][newY] == '.') {
            battlefield[pos.robotPositionX][pos.robotPositionY] = '.'; // Clear old position
            pos.robotPositionX = newX;
            pos.robotPositionY = newY;
            battlefield[newX][newY] = name[0]; // Mark new position
            cout << name << " moved to (" << newX << "," << newY << ").\n";
        }
    }

    void fire() override {
        if (shells <= 0) {
            handleDeath(); // Self-destruct if out of ammo
            return;
        }

        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        int tx = pos.robotPositionX + dx;
        int ty = pos.robotPositionY + dy;

        // Only fire if not targeting self and within bounds
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
                    break; // Only one target per fire
                }
            }
        }
        shells--; // Decrease ammo
    }

    void handleDeath() {
        // Clear battlefield position
        battlefield[pos.robotPositionX][pos.robotPositionY] = '.';
        lives--;

        if (lives > 0) {
            // Respawn in a random empty location
            cout << name << " is respawning...\n";
            Position newPos = findRandomEmptyPosition(M, N, battlefield);
            pos = newPos;
            health = 100;
            shells = 10;
            battlefield[newPos.robotPositionX][newPos.robotPositionY] = name[0];
        } else {
            alive = false;
            cout << name << " has been destroyed.\n";
        }
    }

    void displayAction() override {
        cout << name << " is taking action.\n";
    }
};

// Function to print the battlefield grid
void displayBattlefield() {
    cout << "\nBattlefield:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << battlefield[i][j] << ' ';
        }
        cout << endl;
    }
}

// Simulation engine – loops through all steps and robots
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

        // Stop simulation if only one robot remains
        int aliveCount = 0;
        for (Robot* r : robots)
            if (r->isLives()) aliveCount++;
        if (aliveCount <= 1) break;
    }
    cout << "\nSimulation Ended.\n";
}

// Main function reads config from input.txt and starts simulation
int main() {
    srand(time(0)); // Random seed for movement and fire

    ifstream configFile("input.txt");
    if (!configFile) {
        cerr << "Failed to open input.txt. Please make sure the file exists.\n";
        return 1;
    }

    string line;
    int robotCount = 0;

    // Read input.txt line by line
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
            // Parse robot data
            string type, name, xStr, yStr;
            iss >> type >> name >> xStr >> yStr;

            int x = (xStr == "random") ? rand() % M : stoi(xStr);
            int y = (yStr == "random") ? rand() % N : stoi(yStr);

            // Currently supports GenericRobot
            if (type == "GenericRobot") {
                robots.push_back(new GenericRobot(name, x, y));
            }
        }
    }

    // Initialize the battlefield with empty cells
    battlefield = vector<vector<char>>(M, vector<char>(N, '.'));

    // Mark initial positions of all robots
    for (Robot* r : robots) {
        Position p = r->getPosition();
        battlefield[p.robotPositionX][p.robotPositionY] = r->getName()[0];
    }

    simulate(); // Run simulation

    // Free dynamically allocated memory
    for (Robot* r : robots) delete r;

    return 0;
}
