 /**********|**********|**********|
 Program: Battlefield.cpp 
 Course: OOPDS
 Trimester: 2510
 Name: Sharveeny
 ID: 242UC241DD
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: SHARVEENY.KALAI.KUMAR@student.mmu.edu.my
 Phone: 017-4081106
 **********|**********|**********/


#include "Battlefield.h"

Battlefield::Battlefield(int width, int height) : width(width), height(height) {
    grid.resize(height, std::vector<char>(width, '.')); 
}

void Battlefield::display() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

bool Battlefield::isInBounds(int x, int y) const {
    return (x >= 0 && x < width && y >= 0 && y < height);
}

void Battlefield::placeRobot(int x, int y) {
    if (isInBounds(x, y)) {
        grid[y][x] = 'R'; 
    }
}

void Battlefield::moveRobot(int oldX, int oldY, int newX, int newY) {
    if (isInBounds(newX, newY)) {
        grid[oldY][oldX] = '.'; 
        placeRobot(newX, newY); 
    }
}

void Battlefield::logResults(const std::string& filename) const {
   
}

int Battlefield::getWidth() const {
    return width;
}

int Battlefield::getHeight() const {
    return height;
}

