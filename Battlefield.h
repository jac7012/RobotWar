 /**********|**********|**********|
 Program: Battlefield.h 
 Course: OOPDS
 Trimester: 2510
 Name: Sharveeny
 ID: 242UC241DD
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: SHARVEENY.KALAI.KUMAR@student.mmu.edu.my
 Phone: 017-4081106
 **********|**********|**********/


#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Battlefield {
public:
    Battlefield(int width, int height);
    void display() const;
    bool isInBounds(int x, int y) const;
    void placeRobot(int x, int y);
    void moveRobot(int oldX, int oldY, int newX, int newY);
    void logResults(const std::string& filename) const;
    int getWidth() const;
    int getHeight() const;


private:
    int width;
    int height;
    std::vector<std::vector<char>> grid;
};

#endif 
