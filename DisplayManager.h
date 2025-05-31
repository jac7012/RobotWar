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

#include "battlefield.h"
#include "robot.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

class DisplayManager {
private:
    ofstream logFile;
    string logFilename;
    
public:
    DisplayManager() {
        // Create a timestamped log file
        time_t now = time(0);
        tm* ltm = localtime(&now);
        logFilename = "battle_log_" + 
                     to_string(1900 + ltm->tm_year) + "_" +
                     to_string(1 + ltm->tm_mon) + "_" +
                     to_string(ltm->tm_mday) + "_" +
                     to_string(ltm->tm_hour) + "_" +
                     to_string(ltm->tm_min) + ".txt";
        logFile.open(logFilename);
    }

    ~DisplayManager() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    // Display the battlefield grid
    void displayBattlefield(const Battlefield& battlefield) {
        cout << "\nCurrent Battlefield:\n";
        cout << "  ";
        for (int x = 0; x < battlefield.getWidth(); ++x) {
            cout << setw(2) << x % 10; // Show coordinates (single digit for readability)
        }
        cout << "\n";

        for (int y = battlefield.getHeight()-1; y >= 0; --y) {
            cout << setw(2) << y;
            for (int x = 0; x < battlefield.getWidth(); ++x) {
                Robot* robot = battlefield.getRobotAt(x, y);
                if (robot) {
                    cout << " " << robot->getName()[0]; // Show first letter of robot name
                } else {
                    cout << " .";
                }
            }
            cout << "\n";
        }
        
        // Log to file
        logFile << "\nBattlefield State:\n";
        for (int y = battlefield.getHeight()-1; y >= 0; --y) {
            for (int x = 0; x < battlefield.getWidth(); ++x) {
                Robot* robot = battlefield.getRobotAt(x, y);
                logFile << (robot ? robot->getName()[0] : '.') << " ";
            }
            logFile << "\n";
        }
    }

    // Display turn information
    void displayTurnInfo(int turn) {
        string turnHeader = "=== Turn " + to_string(turn) + " ===";
        cout << "\n" << turnHeader << "\n";
        logFile << "\n" << turnHeader << "\n";
    }

    // Display robot action
    void displayAction(const string& action) {
        cout << "  " << action << "\n";
        logFile << "  " << action << "\n";
    }

    // Display robot stats
    void displayRobotStats(const Robot& robot) {
        cout << "  " << robot.getName() << " - Lives: " << robot.getLives() 
             << ", Shells: " << robot.getShells() << "\n";
        logFile << "  " << robot.getName() << " - Lives: " << robot.getLives() 
                << ", Shells: " << robot.getShells() << "\n";
    }

    // Display game over message
    void displayGameOver(const vector<Robot*>& robots) {
        int aliveCount = 0;
        string winner;
        
        for (const Robot* robot : robots) {
            if (robot->isAlive()) {
                aliveCount++;
                winner = robot->getName();
            }
        }
        
        if (aliveCount == 1) {
            string message = "Game Over! " + winner + " is the winner!";
            cout << "\n" << message << "\n";
            logFile << "\n" << message << "\n";
        } else {
            string message = "Game Over! Simulation ended with " + to_string(aliveCount) + " robots remaining.";
            cout << "\n" << message << "\n";
            logFile << "\n" << message << "\n";
        }
    }
};

#endif
