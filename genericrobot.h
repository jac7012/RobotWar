#ifndef GENERICROBOT_H
#define GENERICROBOT_H

#include "newrobot.h"
#include "Battlefield.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



class GenericRobot: public virtual Robot, public ThinkingRobot,  public SeeingRobot, public ShootingRobot, public MovingRobot
{
    private:
        vector<string> availableUpgrades;
    bool hasMoved;
    bool hasFired;
    bool hasLooked;
    string currentSeeingUpgrade; // Add this to store the chosen upgrade
    string currentMovingUpgrade;    // Add this to store the chosen moving upgrade
    string currentShootingUpgrade;  // Add this to store the chosen shooting upgrade
    public:
        // constructor
        GenericRobot(const string& name, int startX, int startY, int w, int h)
        : Robot(name, startX, startY, w, h),
          ThinkingRobot(name, startX, startY),
          SeeingRobot(name, startX, startY),
          ShootingRobot(name, startX, startY),
          MovingRobot(name, startX, startY),
          hasMoved(false), hasFired(false), hasLooked(false) 
          {
        availableUpgrades = {"Moving", "Shooting", "Seeing"};
        pos.robotPositionX = startX;
        pos.robotPositionY = startY;
        }

    virtual void think() override 
    { 
        if (shells <= 0) 
        {
            cout << name << " has no shells left. Self-destructed!\n";
            health = 0;
        }
    }

    //look around in the center position
    virtual void look(int x, int y) 
    {
        int centerX = pos.robotPositionX + x;   // center x and y
        int centerY = pos.robotPositionY + y;

        for (int i = -1; i <= 1; ++i)   // check surrounding position
        {
            for (int j = -1; j <= 1; ++j)
            {
                int lookX = centerX + i;
                int lookY = centerY + j;

                // check if the position is inside battlefield
                bool inBattlefield = (lookX >= 0 && lookX < fieldWidth &&
                            lookY >= 0 && lookY < fieldHeight);
                
            }
        }
        /*no cout surrounding robot*/
    }


    // shoot the robot
    virtual void fire(Battlefield* battlefield, int x, int y) 
      // shoot in the direction of x, y
    { 
        if (shells <=0) return;  // no shells left, cannot shoot

        if (x < -1 || x > 1 || y < -1 || y > 1 || (x == 0 && y == 0)) return; //cannot shoot at self and out of range
        shells--;                  // reduce shells by 1 when used

        // calculate target position
        int targetX = pos.robotPositionX + x;
        int targetY = pos.robotPositionY + y;

        // check if target position is inside battlefield
        if (targetX < 0 || targetX >= fieldWidth ||
            targetY < 0 || targetY >= fieldHeight)
            return; 

        if(rand() % 100 < 70) // 70% chance to hit
        {
            int damage = rand() % 71; //0-70%

            // get the target robot at the target position
            Robot* target = battlefield->getRobotAt(targetX, targetY);
            if (target != nullptr && target->isLives())
            {
                target->takeDamage(damage);
                std::cout << name << " hit " << target->getName() << " for " << damage << " damage.\n";
            }

        
        } 
    }

    Position calNewPosition(int direction);   // calculate new position based on direction

    // Check if the new position is inside battlefield 
    bool isValidMove(Position p);

    virtual void move(int direction);

    // Add this method to allow choosing a seeing upgrade
    void chooseSeeingUpgrade(const string& upgradeName) {
        // You can expand this logic as needed
        if (find(availableUpgrades.begin(), availableUpgrades.end(), upgradeName) != availableUpgrades.end()) {
            currentSeeingUpgrade = upgradeName;
            cout << "Seeing upgrade chosen: " << upgradeName << endl;
        } else {
            cout << "Upgrade not available: " << upgradeName << endl;
        }
    }

    // Add this method to allow choosing a moving upgrade
    void chooseMovingUpgrade(const string& upgradeName) {
        // You can expand this logic as needed
        if (find(availableUpgrades.begin(), availableUpgrades.end(), upgradeName) != availableUpgrades.end()) {
            currentMovingUpgrade = upgradeName;
            cout << "Moving upgrade chosen: " << upgradeName << endl;
        } else {
            cout << "Upgrade not available: " << upgradeName << endl;
        }
    }

    // Add this method to allow choosing a shooting upgrade
    void chooseShootingUpgrade(const string& upgradeName) {
        // You can expand this logic as needed
        if (find(availableUpgrades.begin(), availableUpgrades.end(), upgradeName) != availableUpgrades.end()) {
            currentShootingUpgrade = upgradeName;
            cout << "Shooting upgrade chosen: " << upgradeName << endl;
        } else {
            cout << "Upgrade not available: " << upgradeName << endl;
        }
    }

    virtual void displayStats() const {
        cout << "Name: " << name
             << " | Health: " << health
             << " | Shells: " << shells
             << " | Lives: " << lives
             << " | Hidden: " << (hidden ? "Yes" : "No")
             << endl;
    }

};

// Implementation of member functions outside the class definition

inline Position GenericRobot::calNewPosition(int direction)
{
    Position newPos = pos;      //start with current position
    switch (direction)
    {
        case 0: // Up
            newPos.robotPositionY+= 1;
            break;
        case 1: // Left up
            newPos.robotPositionX-=1;
            newPos.robotPositionY+=1;
            break;
        case 2: // Right up
            newPos.robotPositionX+=1;
            newPos.robotPositionY+=1;
            break;
        case 3: // Left
            newPos.robotPositionX-=1;
            break;
        case 4: // Right
            newPos.robotPositionX+=1;
            break;
        case 5: // Down
            newPos.robotPositionY-=1;
            break;
        case 6: // Left down
            newPos.robotPositionX-=1;
            newPos.robotPositionY-=1;
            break;
        case 7: // Right down
            newPos.robotPositionX+=1;
            newPos.robotPositionY-=1;
            break;
        default:
            break;
    }
    return newPos;
}

inline bool GenericRobot::isValidMove(Position p)
{
    return (p.robotPositionX >= 0 && p.robotPositionX < fieldWidth &&
            p.robotPositionY >= 0 && p.robotPositionY < fieldHeight);
}

inline void GenericRobot::move(int direction)
{
    Position newPos = calNewPosition(direction);
    if(isValidMove(newPos))
    {
        pos = newPos;
    }
}


#endif


