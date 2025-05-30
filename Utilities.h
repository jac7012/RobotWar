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

#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include "Position.h"

using namespace std;

namespace Utilities {
    // Initialize random seed
    inline void initRandom() {
        srand(static_cast<unsigned>(time(nullptr)));
    }
    
    // Generate random number between min and max
    inline int randomInt(int min, int max) {
        return min + rand() % (max - min + 1);
    }
    
    // Check if a position is within battlefield bounds
    inline bool isInBounds(int x, int y, int width, int height) {
        return x >= 0 && x < width && y >= 0 && y < height;
    }
    
    // Calculate distance between two positions
    inline int calculateDistance(const Position& p1, const Position& p2) {
        return abs(p1.robotPositionX - p2.robotPositionX) + abs(p1.robotPositionY - p2.robotPositionY);
    }
    
    // Find a random empty position on the battlefield
    inline Position findRandomEmptyPosition(int width, int height, const vector<vector<char>>& grid) {
        Position pos;
        do {
            pos.robotPositionX = randomInt(0, width - 1);
            pos.robotPositionY = randomInt(0, height - 1);
        } while (grid[pos.robotPositionX][pos.robotPositionY] != '.');
        return pos;
    }
    
    // Direction enum for movement
    enum Direction {
        UP, UP_LEFT, UP_RIGHT, 
        LEFT, RIGHT, 
        DOWN, DOWN_LEFT, DOWN_RIGHT
    };
    
    // Convert direction to dx, dy
    inline pair<int, int> directionToDelta(Direction dir) {
        switch (dir) {
            case UP: return {0, 1};
            case UP_LEFT: return {-1, 1};
            case UP_RIGHT: return {1, 1};
            case LEFT: return {-1, 0};
            case RIGHT: return {1, 0};
            case DOWN: return {0, -1};
            case DOWN_LEFT: return {-1, -1};
            case DOWN_RIGHT: return {1, -1};
            default: return {0, 0};
        }
    }
};

#endif // UTILITIES_H
