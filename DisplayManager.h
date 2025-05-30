/**********|**********|**********|
 Program: DisplayManager.h 
 Course: OOPDS
 Trimester: 2510
 Name: Abikirthikka
 ID: 242UC24420
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: ABIKIRTHIKKA.TAMIL.ARASAN@student.mmu.edu.my
 Phone: 014-9350432
 **********|**********|**********/
#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "Battlefield.h"
#include "Robot.h"
#include "Constants.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class DisplayManager {
private:
    ofstream logFile;
    string logFilename;

public:
    DisplayManager(const string& filename = "robot_war_log.txt") : logFilename(filename) {
        logFile.open(logFilename);
        if (!logFile.is_open()) {
            cerr << "Error: Could not open log file!" << endl;
        }
    }

    ~DisplayManager() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    // Display the battlefield grid
    void displayBattlefield(const Battlefield& battlefield) {
        // Clear console (works on most systems)
        system("cls || clear");
        
        cout << "\n=== ROBOT WAR SIMULATION ===\n";
        cout << "Battlefield (" << battlefield.getWidth() << "x" << battlefield.getHeight() << "):\n";
        
        // Display column numbers
        cout << "   ";
        for (int x = 0; x < battlefield.getWidth(); x++) {
            cout << setw(2) << x % 10 << " ";
        }
        cout << "\n";

        for (int y = battlefield.getHeight() - 1; y >= 0; y--) {
            // Display row number
            cout << setw(2) << y << " ";
            
            for (int x = 0; x < battlefield.getWidth(); x++) {
                Robot* robot = battlefield.getRobotAt(x, y);
                if (robot) {
                    cout << robot->getName()[0] << "  ";
                } else {
                    cout << ".  ";
                }
            }
            cout << "\n";
        }
        cout << "\nLegend: ";
        for (Robot* robot : battlefield.getRobots()) {
            if (robot->isAlive()) {
                cout << robot->getName()[0] << "=" << robot->getName() << " ";
            }
        }
        cout << "\n";
        
        // Log to file
        logFile << "\n=== BATTLEFIELD STATE ===\n";
        for (int y = battlefield.getHeight() - 1; y >= 0; y--) {
            for (int x = 0; x < battlefield.getWidth(); x++) {
                Robot* robot = battlefield.getRobotAt(x, y);
                logFile << (robot ? robot->getName()[0] : '.') << " ";
            }
            logFile << "\n";
        }
    }

    // Display robot actions
    void displayAction(const string& action) {
        cout << "> " << action << "\n";
        logFile << "> " << action << "\n";
    }

    // Display turn information
    void displayTurnInfo(int turn) {
        string turnHeader = "=== TURN " + to_string(turn) + " ===";
        cout << "\n" << turnHeader << "\n";
        logFile << "\n" << turnHeader << "\n";
    }

    // Display game over message
    void displayGameOver(const vector<Robot*>& robots) {
        vector<string> survivors;
        for (Robot* robot : robots) {
            if (robot->isAlive()) {
                survivors.push_back(robot->getName());
            }
        }

        if (survivors.empty()) {
            cout << "\nGAME OVER: All robots have been destroyed!\n";
            logFile << "\nGAME OVER: All robots have been destroyed!\n";
        } else if (survivors.size() == 1) {
            cout << "\nGAME OVER: " << survivors[0] << " is the last robot standing!\n";
            logFile << "\nGAME OVER: " << survivors[0] << " is the last robot standing!\n";
        } else {
            cout << "\nGAME OVER: Simulation ended with multiple survivors:\n";
            logFile << "\nGAME OVER: Simulation ended with multiple survivors:\n";
            for (const string& name : survivors) {
                cout << "- " << name << "\n";
                logFile << "- " << name << "\n";
            }
        }
    }

    // Display robot stats
    void displayRobotStats(const Robot* robot) {
        cout << "\n" << robot->getName() << " stats:\n";
        cout << "- Position: (" << robot->getX() << ", " << robot->getY() << ")\n";
        cout << "- Lives: " << robot->getLives() << "\n";
        cout << "- Shells: " << robot->getShells() << "\n";
        cout << "- Upgrade Level: " << robot->getUpgradeLevel() << "\n";
        
        logFile << "\n" << robot->getName() << " stats:\n";
        logFile << "- Position: (" << robot->getX() << ", " << robot->getY() << ")\n";
        logFile << "- Lives: " << robot->getLives() << "\n";
        logFile << "- Shells: " << robot->getShells() << "\n";
        logFile << "- Upgrade Level: " << robot->getUpgradeLevel() << "\n";
    }
};

#endif // DISPLAYMANAGER_H

