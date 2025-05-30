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
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DisplayManager {
private:
    ofstream logFile;
    string logFilename;
    
public:
    DisplayManager(const string& filename = "battle_log.txt") : logFilename(filename) {
        logFile.open(logFilename);
        if (!logFile) {
            cerr << "Error opening log file!" << endl;
        }
    }
    
    ~DisplayManager() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
    
    void displayBattlefield(const Battlefield& battlefield) {
        // Clear screen (platform specific)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        cout << "\nCurrent Battlefield:\n";
        for (int i = 0; i < battlefield.getHeight(); ++i) {
            for (int j = 0; j < battlefield.getWidth(); ++j) {
                cout << battlefield.getCell(i, j) << ' ';
            }
            cout << endl;
        }
        cout << endl;
        
        // Log to file
        logFile << "\nCurrent Battlefield:\n";
        for (int i = 0; i < battlefield.getHeight(); ++i) {
            for (int j = 0; j < battlefield.getWidth(); ++j) {
                logFile << battlefield.getCell(i, j) << ' ';
            }
            logFile << endl;
        }
        logFile << endl;
    }
    
    void displayRobotAction(const string& action) {
        cout << action << endl;
        logFile << action << endl;
    }
    
    void displayTurnHeader(int turn) {
        string header = "--- Turn " + to_string(turn) + " ---";
        cout << header << endl;
        logFile << header << endl;
    }
    
    void displayGameOver(const vector<Robot*>& robots) {
        int aliveCount = 0;
        string winner;
        
        for (const auto& robot : robots) {
            if (robot->isLives()) {
                aliveCount++;
                winner = robot->getName();
            }
        }
        
        if (aliveCount <= 1) {
            string message = (aliveCount == 1) 
                ? "Game Over! Winner: " + winner
                : "Game Over! All robots destroyed!";
                
            cout << message << endl;
            logFile << message << endl;
        }
    }
    
    void displayRobotStats(const Robot* robot) {
        robot->displayStats();
        // You could also log this if needed
    }
};

#endif // DISPLAYMANAGER_H
