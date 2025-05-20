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

SimulationManager::SimulationManager(const std::string& inputFile)
    : battlefield(0, 0), steps(0), robotCount(0) {
    parseInputFile(inputFile);
}

void SimulationManager::runSimulation() {
    std::cout << "Simulation initialized.\n";
    std::cout << "Battlefield size: " << battlefield.getWidth() << " x " << battlefield.getHeight() << "\n";
    std::cout << "Steps to simulate: " << steps << "\n";
    std::cout << "Number of robots: " << robotCount << "\n";

    
    battlefield.display();
}

void SimulationManager::parseInputFile(const std::string& inputFile) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open input file: " << inputFile << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);

        if (line.find("M by N") != std::string::npos) {
            std::string dummy;
            int width, height;
            iss >> dummy >> dummy >> dummy >> width >> height;
            battlefield = Battlefield(width, height);
        }
        else if (line.find("steps:") != std::string::npos) {
            std::string dummy;
            iss >> dummy >> steps;
        }
        else if (line.find("robots:") != std::string::npos) {
            std::string dummy;
            iss >> dummy >> robotCount;
        }
        else if (!line.empty() && isalpha(line[0])) {
            std::string type, name, xStr, yStr;
            iss >> type >> name >> xStr >> yStr;

            int x, y;
            if (xStr == "random" || yStr == "random") {
                x = rand() % battlefield.getWidth();
                y = rand() % battlefield.getHeight();
            } else {
                x = std::stoi(xStr);
                y = std::stoi(yStr);
            }

            std::cout << "Parsed robot: " << type << " " << name << " at (" << x << "," << y << ")\n";
            battlefield.placeRobot(x, y);
        }
    }

    file.close();
}
