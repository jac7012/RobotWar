/**********|**********|**********|
 Program: Utilities.h 
 Course: OOPDS
 Trimester: 2510
 Name: Abikirthikka
 ID: 242UC24420
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: ABIKIRTHIKKA.TAMIL.ARASAN@student.mmu.edu.my
 Phone: 014-9350432
 **********|**********|**********/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <ctime>
#include <utility>
#include <algorithm>
#include "Constants.h"

class Utilities {
public:
    static void initializeRandom();
    
    static int getRandomInt(int min, int max);
    static double getRandomDouble(double min, double max);
    static bool probabilityCheck(double probability);
    static std::pair<int, int> getRandomPosition(int width, int height);
    
    static Direction getRandomDirection();
    static std::string directionToString(Direction dir);
    
    static std::string toUpper(const std::string& str);
    static std::string trim(const std::string& str);
};

#endif // UTILITIES_H
