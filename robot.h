/**********|**********|**********|
 Program: robot.h
 Course: OOPDS
 Trimester: 2510
 Name: Bianca Lau Ying Xuan
 ID: 242UC2426R
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: BIANCA.LAU.YING@student.mmu.edu.my
 Phone: 010-2752246
  **********|**********|**********/

#ifndef ROBOT_H
#define ROBOT_H

#include "battlefield.h"  
#include "Constants.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

class Battlefield; // Forward declaration

struct Position           // Position to hold coordinate (x, y)
{
    int robotPositionX;
    int robotPositionY;
};

// base class Robot
class Robot
{
    protected:
       Position pos;       //current position of the robot
       std::string name;   // name of the robot
       int lives;          // number of lives
       bool alive;         // is the robot alive
       int shells;         // number of shells
       int upgradeLevel;   // upgrade level of the robot
       int battlefieldWidth;
       int battlefieldHeight;

    public:
       // Default constructor
       Robot()
           : name("Default"), pos{0, 0}, lives(3), shells(10), upgradeLevel(0),
             battlefieldWidth(1), battlefieldHeight(1), alive(true) {}

       //constructor for set initial values
       Robot(const std::string& name, int startX, int startY, int w, int h)
    : name(name),
      pos{startX, startY},
      lives(3),
      shells(10),
      upgradeLevel(0),
      battlefieldWidth(w),
      battlefieldHeight(h),
      alive(true){}

      virtual ~Robot() = default;

      // Set the robot's position for battlefield control
      void setPosition(int x, int y)
      {
        pos.robotPositionX = x;
        pos.robotPositionY = y;
      }


       Position getPosition() const
       {
           return pos;
       }

       int getX() const
       {
           return pos.robotPositionX;
       }

       int getY() const
       {
           return pos.robotPositionY;
       }

       std::string getName() const
       {
           return name;
       }

       int getLives() const
       {
           return lives;
       }

       bool isAlive() const
       {
           return alive;
       }

       int getShells() const
       {
           return shells;
       }

       int getUpgradeLevel() const
       {
           return upgradeLevel;
       }

       //reduce lives when damage
       void takeDamage(const std::string& attackerName, Battlefield* battlefield)
       {
            lives--;            // reduce lives by 1 if health < 0
            if (lives > 0)
            {
                std::cout << attackerName << "hit" << name << "." << std::endl
                << name << "has" << lives << "lives left." << std::endl ;
                respawnRandom(battlefield);
            }
            else
            {
                alive = false;
                std::cout << attackerName << "killed" << name << "!" << std::endl ;
            }

       }

       // respawn robot randomly
       void respawnRandom(Battlefield*battlefield)
       {
           alive= true;
           shells = 10;
           battlefield -> removeRobot(this);   //remove robot from old position
           Position newPos= battlefield -> findRandomEmptyPosition();   // find empty position From battlefield.h
           battlefield -> placeRobot(this,newPos.robotPositionX,newPos.robotPositionY); //put robot to new position
           setPosition (newPos.robotPositionX, newPos.robotPositionY);  //update position

           std:: cout <<name << "has respawned at (" << pos.robotPositionX
           << ", " << pos.robotPositionY << "). " << endl;
       }

};

class MovingRobot {
public:
    virtual void move(int direction) = 0;
    virtual ~MovingRobot() {}
};

class ShootingRobot {
public:
    virtual void fire(int dx, int dy) = 0;
    virtual ~ShootingRobot() {}
};

class SeeingRobot {
public:
    virtual void look(int offsetX, int offsetY) = 0;
    virtual ~SeeingRobot() {}
};

class ThinkingRobot {
public:
    virtual void think() = 0;
    virtual ~ThinkingRobot() {}
};


#endif
