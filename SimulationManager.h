 /**********|**********|**********|
 Program: SimulationManager.h
 Course: OOPDS
 Trimester: 2510
 Name: Sharveeny
 ID: 242UC241DD
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: SHARVEENY.KALAI.KUMAR@student.mmu.edu.my
 Phone: 017-4081106
 **********|**********|**********/

#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "Battlefield.h"
#include <string>
#include <iostream>

class SimulationManager {
public:
    SimulationManager(const std::string& inputFile);
    void runSimulation();
    void parseInputFile(const std::string& inputFile);

private:
    Battlefield battlefield;
    int steps;
    int robotCount;
};

#endif 