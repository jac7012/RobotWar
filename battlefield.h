#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "robot.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std; 



class Robot; // Forward declaration
             /*to avoid compilation errors caused by header files
             including each other, while being able to use Robot*
             in the interface.
             */



// This class represents the battlefield grid where robots will be placed and move around
class Battlefield {
public:
    // Constructor: Initializes battlefield with given width and height
    Battlefield(int width, int height);

    ~ Battlefield()
    {
       for (Robot* robot : robots)
       {
        delete robot;
       }
    }

    // Displays the battlefield grid to the console
    void display() const
    {
       for (int y = 0; y < height; y++)
       {
          for (int x = 0; x < width; x++)
          {
             if (grid[x][y] == nullptr)
                cout << ". ";
             else
                cout << grid[x][y] -> getName()[0] << " " ;
          }
          cout << endl;
       }
    }



    // Checks if a given (x, y) coordinate is within the battlefield bounds
    bool isInBounds(int x, int y) const
    {
       return (x >= 0 && x < width && y >= 0 && y < height);
    }

    // Places a robot character on the battlefield at a specific coordinate
    void placeRobot(Robot* robot, int x, int y)
    {
        grid[x][y] = robot ;
        robots.push_back(robot);
        robot -> setPosition(x,y);

    }

    void placeRobotRandomly(Robot* robot)
    {
       Position pos = findRandomEmptyPosition();
       placeRobot(robot, pos.robotPositionX, pos.robotPositionY);
    }

    // Update robot move position
    void moveRobot(Robot* robot, int newX, int newY)
    {
       Position currentPos = robot -> getPosition();
       grid[currentPos.robotPositionX][currentPos.robotPositionY] = nullptr; // clear current position
       grid[newX][newY] = robot;                                             // put the new position
       robot->setPosition(newX, newY);           //update the new position of the robot
    }


    // Logs the results or final state of the battlefield to a file
    void logResults(const string& filename) const
    {
       ofstream file(filename);
       if (!file.is_open())
       {
          cerr << "Cannot open file " << filename << " for writing!" << endl;
          return;
       }

       for (int y = 0; y < height; y++)
       {
           for (int x = 0; x < width; x++)
           {
               if (grid[x][y] == nullptr)
                   file << ". ";
               else
                   file << "R ";
           }
           file << endl;
       }
       file.close();
    }

    // Getter for battlefield width
    int getWidth() const
    {
        return width;
    }

    // Getter for battlefield height
    int getHeight() const
    {
        return height;
    }

    //for upgrades
    Robot* getRobotAt(int x, int y)
    {
       if(!isInBounds(x, y))
          return nullptr;

       return grid[x][y];
    }

    bool isValidMove(const Position& pos)
    {
       return isInBounds(pos.robotPositionX, pos.robotPositionY) && isEmpty(pos.robotPositionX, pos.robotPositionY);
    }

    void revealAllToRobot(Robot* robot)
    {
       cout << "Revealing all robots to " << robot->getName() << ":" << endl;
       for (Robot* r : robots)
       {
           cout << r->getName() << " at (" << r->getX() << ", " << r->getY() << ")" << endl;
       }
    }


    Robot* getRobotByName(const string& name)
    {
       for (Robot* r : robots)
       {
          if (r->getName() == name)
            return r;
       }
    return nullptr;
    }

    //To get all robots
    const std::vector<Robot*>& getRobots() const
    { return robots; }

    Position findRandomEmptyPosition() const
    {
       Position pos;
       do
       {
           pos.robotPositionX = rand() % width;
           pos.robotPositionY = rand() % height;
       }
       while (!isEmpty(pos.robotPositionX, pos.robotPositionY));

       return pos;
    }

    bool isEmpty(int x, int y) const
    {
       if (!isInBounds(x, y)) return false;
       return grid[x][y] == nullptr;
    }

    void removeRobot(Robot* robot)
    {
        Position pos= robot->getPosition();
        if (isInBounds(pos.robotPositionX, pos.robotPositionY))
        grid[pos.robotPositionX][pos.robotPositionY] = nullptr;
    }

private:
    int width;  // Width of the battlefield grid (number of columns)
    int height; // Height of the battlefield grid (number of rows)

    // 2D robot pointer table to indicate which robot object is placed in the grid on the battlefield.
    std::vector<std::vector<Robot*>> grid;

    std::vector<Robot*> robots;


};

#endif



/*
In cpp,
Battlefield::Battlefield(int width, int height) : width(width), height(height)
{
    grid.resize(width, std::vector<Robot*>(height, nullptr));
}


}
*/



