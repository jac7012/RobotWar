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
***********|**********|**********/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "newrobot.h" // Contains base Robot class and Position struct
using namespace std;

const int M = 20; // Number of rows in battlefield
const int N = 40; // Number of columns in battlefield
const int MAX_STEPS = 100; // Maximum number of turns in the simulation

class Robot; // Forward declaration of Robot class

// Initialize the battlefield with empty cells ('.')
vector<vector<char>> battlefield(M, vector<char>(N, '.'));

// Vector to store all robot pointers
vector<Robot*> robots;

// Utility function to find a random empty position on the battlefield
Position findRandomEmptyPosition(int rows, int cols, const vector<vector<char>>& battlefield) {
    Position pos;
    do {
        pos.robotPositionX = rand() % rows;
        pos.robotPositionY = rand() % cols;
    } while (battlefield[pos.robotPositionX][pos.robotPositionY] != '.'); // Repeat until empty cell is found
    return pos;
}

// GenericRobot is a subclass of Robot with basic AI behavior
class GenericRobot : public Robot {
public:
    // Constructor - initializes robot with a name and position, and marks it on the battlefield
    GenericRobot(string n, int xPos, int yPos)
        : Robot(n, xPos, yPos, N, M) {
        battlefield[xPos][yPos] = name[0]; // Use first letter of name as symbol
    }

    // Empty think() function – can be extended for smarter decision-making
    void think() override {}

    // Robot scans the surroundings (prints a message for now)
    void look() override {
        cout << name << " looks around.\n";
    }

    // Move robot to a random adjacent empty cell
    void move() override {
        int dx = rand() % 3 - 1; // -1, 0 or 1
        int dy = rand() % 3 - 1; // -1, 0 or 1
        int newX = pos.robotPositionX + dx;
        int newY = pos.robotPositionY + dy;

        // Only move if within bounds and new cell is empty
        if (newX >= 0 && newX < M && newY >= 0 && newY < N && battlefield[newX][newY] == '.') {
            battlefield[pos.robotPositionX][pos.robotPositionY] = '.'; // Clear old position
            pos.robotPositionX = newX;
            pos.robotPositionY = newY;
            battlefield[pos.robotPositionX][pos.robotPositionY] = name[0]; // Mark new position
            cout << name << " moved to (" << newX << "," << newY << ").\n";
        }
    }

    // Robot fires at a random adjacent cell
    void fire() override {
        if (shells <= 0) {
            handleDeath(); // If out of shells, trigger respawn or death
            return;
        }

        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        int tx = pos.robotPositionX + dx;
        int ty = pos.robotPositionY + dy;

        // Only fire if direction is not (0,0) and target is within bounds
        if ((dx != 0 || dy != 0) && tx >= 0 && tx < M && ty >= 0 && ty < N) {
            for (Robot* r : robots) {
                if (r->isLives() && r != this &&
                    tx == r->getPosition().robotPositionX &&
                    ty == r->getPosition().robotPositionY) {

                    // 70% chance to hit target
                    if ((rand() % 100) < 70) {
                        r->takeDamage(100); // Inflict full damage
                        cout << name << " fired and hit " << r->getName() << "!\n";
                    } else {
                        cout << name << " fired and missed.\n";
                    }
                    break; // Only attack one target
                }
            }
        }
        shells--; // Use up one shell per fire attempt
    }

    // Handles robot death and respawn
    void handleDeath() {
        battlefield[pos.robotPositionX][pos.robotPositionY] = '.'; // Clear current cell
        lives--; // Decrease life count

        if (lives > 0) {
            // Respawn robot at random empty location
            cout << name << " is respawning...\n";
            Position newPos = findRandomEmptyPosition(M, N, battlefield);
            pos = newPos;
            health = 100; // Reset health
            shells = 10;  // Reset ammo
            battlefield[pos.robotPositionX][pos.robotPositionY] = name[0]; // Mark battlefield
        } else {
            alive = false; // Mark as destroyed
            cout << name << " has been destroyed.\n";
        }
    }

    // Displays robot action message
    void displayAction() override {
        cout << name << " is taking action.\n";
    }
};

// Prints the current state of the battlefield
void displayBattlefield() {
    cout << "\nBattlefield:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << battlefield[i][j] << ' ';
        }
        cout << endl;
    }
}

// Main simulation loop
void simulate() {
    for (int step = 0; step < MAX_STEPS; ++step) {
        cout << "\n--- Turn " << step + 1 << " ---\n";
        displayBattlefield();

        for (Robot* r : robots) {
            if (r->isLives()) {
                r->displayAction();
                r->think();  // Placeholder for future AI logic
                r->look();   // Print look message
                r->fire();   // Try to attack another robot
                r->move();   // Move to new position
            }
        }

        // Check if only one or zero robots are left alive
        int aliveCount = 0;
        for (Robot* r : robots) if (r->isLives()) aliveCount++;
        if (aliveCount <= 1) break; // End simulation if only one robot left
    }
    cout << "\nSimulation Ended.\n";
}

// Main function - sets up robots and starts the simulation
int main() {
    srand(time(0)); // Seed random generator

    // Add robots to the battlefield
    robots.push_back(new GenericRobot("Kidd", 3, 6));
    robots.push_back(new GenericRobot("Jet", 12, 1));
    robots.push_back(new GenericRobot("Alpha", 15, 20));
    robots.push_back(new GenericRobot("Beta", 10, 25));
    robots.push_back(new GenericRobot("Star", rand() % M, rand() % N)); // Random spawn position

    simulate(); // Start simulation

    // Clean up allocated memory
    for (Robot* r : robots) delete r;

    return 0;
}
