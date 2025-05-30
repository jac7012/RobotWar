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


#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include "Robot.h"
#include "Battlefield.h"
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

class DisplayManager {
public:
    DisplayManager(int width, int height);
    ~DisplayManager();
    
    void initializeDisplay();
    void updateDisplay(const std::vector<Robot*>& robots);
    void logAction(const std::string& action);
    void clearScreen();
    void printBattlefield() const;
    void saveToFile(const std::string& filename) const;
    
    // Helper functions for display formatting
    std::string formatRobotInfo(const Robot* robot) const;
    std::string formatPosition(int x, int y) const;
    
private:
    int width;
    int height;
    std::vector<std::vector<char>> battlefield;
    std::vector<std::string> actionLog;
    std::ofstream logFile;
    
    void clearBattlefield();
    char getRobotSymbol(const Robot* robot) const;
    void drawBorders();
};

#endif // DISPLAY_MANAGER_H