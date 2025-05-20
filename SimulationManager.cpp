 /**********|**********|**********|
 Program: SimulationManager.cpp 
 Course: OOPDS
 Trimester: 2510
 Name: Sharveeny
 ID: 242UC241DD
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: SHARVEENY.KALAI.KUMAR@student.mmu.edu.my
 Phone: 017-4081106
 **********|**********|**********/

#include "SimulationManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

SimulationManager::SimulationManager(const string& inputFile)
    : battlefield(0, 0), steps(0), robotCount(0) {
    parseInputFile(inputFile);
}

void SimulationManager::runSimulation() {
    cout << "Simulation initialized.\n";
    cout << "Battlefield size: " << battlefield.getWidth() << " x " << battlefield.getHeight() << "\n";
    cout << "Steps to simulate: " << steps << "\n";
    cout << "Number of robots: " << robotCount << "\n";

    
    battlefield.display();
}

void SimulationManager::parseInputFile(const string& inputFile) {
    ifstream file(inputFile);
    if (!file.is_open()) {
        cerr << "Error: Cannot open input file: " << inputFile << "\n";
        return;
    }

    tring line;
    while (getline(file, line)) {
        istringstream iss(line);

        if (line.find("M by N") != string::npos) {
           string dummy;
            int width, height;
            iss >> dummy >> dummy >> dummy >> width >> height;
            battlefield = Battlefield(width, height);
        }
        else if (line.find("steps:") != string::npos) {
            std::string dummy;
            iss >> dummy >> steps;
        }
        else if (line.find("robots:") != string::npos) {
            string dummy;
            iss >> dummy >> robotCount;
        }
        else if (!line.empty() && isalpha(line[0])) {
            string type, name, xStr, yStr;
            iss >> type >> name >> xStr >> yStr;

            int x, y;
            if (xStr == "random" || yStr == "random") {
                x = rand() % battlefield.getWidth();
                y = rand() % battlefield.getHeight();
            } else {
                x = stoi(xStr);
                y = stoi(yStr);
            }

            cout << "Parsed robot: " << type << " " << name << " at (" << x << "," << y << ")\n";
            battlefield.placeRobot(x, y);
        }
    }

    file.close();
}
