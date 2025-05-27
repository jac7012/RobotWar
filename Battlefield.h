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

// This class represents the battlefield grid where robots will be placed and move around
class Battlefield {
public:
    // Constructor: Initializes battlefield with given width and height
    Battlefield(int width, int height);

    // Displays the battlefield grid to the console
    void display() const;

    // Checks if a given (x, y) coordinate is within the battlefield bounds
    bool isInBounds(int x, int y) const;

    // Places a robot character on the battlefield at a specific coordinate
    void placeRobot(int x, int y);

    // Moves a robot from old (x, y) to new (x, y) if valid
    void moveRobot(int oldX, int oldY, int newX, int newY);

    // Logs the results or final state of the battlefield to a file
    void logResults(const std::string& filename) const;

    // Getter for battlefield width
    int getWidth() const;

    // Getter for battlefield height
    int getHeight() const;

private:
    int width;  // Width of the battlefield grid (number of columns)
    int height; // Height of the battlefield grid (number of rows)

    // 2D grid representing the battlefield. Each cell holds a character (e.g., '.', 'A', 'B')
    std::vector<std::vector<char>> grid;
};

#endif
