#ifndef FIREROBOT_H
#define FIREROBOT_H

#include "newrobot.h"
#include "Battlefield.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

//can shoot anywhere in the battlefield

class FireRobot: public ShootingRobot
{
    public:
        // constructor
        FireRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}
        
        // shoot the robot
         virtual void fire(int x, int y) override

       { 
           if (shells <=0) return;  // no shells left, cannot shoot

          if (x < -1 || x > 1 || y < -1 || y > 1 || (x == 0 && y == 0)) return; //cannot shoot at self and out of range
           shells--;                  // reduce shells by 1 when used

           // calculate target position
           int targetX = pos.robotPositionX + x;
           int targetY = pos.robotPositionY + y;

              // check if target position is inside battlefield
           if (targetX < 0 || targetX >= battlefieldWidth ||
              targetY < 0 || targetY >= battlefieldHeight)
               return; 

           if(rand() % 100 < 70) // 70% chance to hit
           {
               int damage = rand() % 71; //0-70%
           }
        }
        
};


#endif