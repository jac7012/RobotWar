#ifndef SUPPORTROBOT_H
#define SUPPORTROBOT_H

#include "newrobot.h"
#include "Battlefield.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

// can look bigger (5x5) and only move left right 
class ScoutRobot: public Robot, public SeeingRobot, public MovingRobot
{
    public:
        // constructor
        ScoutRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}
        
       //look around in the center position
       virtual void look(int x, int y) 
       {
           int centerX = pos.robotPositionX + x;   // center x and y
           int centerY = pos.robotPositionY + y;

           for (int i = -2; i <= 2; ++i)   // check surrounding position
           {
               for (int j = -2; j <= 2; ++j)
               {
                   int lookX = centerX + i;
                   int lookY = centerY + j;

                   // check if the position is inside battlefield
                   bool inBattlefield = (lookX >= 0 && lookX < battlefieldWidth &&
                               lookY >= 0 && lookY < battlefieldHeight);
                   
               }
           }
       }

       Position calNewPosition(int direction)   // calculate new position based on direction
       {
           Position newPos = pos;      //start with current position
           switch (direction)
           {
               case 0: // Left
                   newPos.robotPositionX-=1;
                   break;
               case 1: // Right
                   newPos.robotPositionX+=1;
                   break;
               default:
                   break;
           }
           return newPos;
       }

       // Check if the new position is inside battlefield 
       bool isValidMove(Position p)
       {
           return (p.robotPositionX >= 0 && p.robotPositionX < battlefieldWidth &&
                   p.robotPositionY >= 0 && p.robotPositionY < battlefieldHeight);
       }
    
       virtual void move(int direction) override
       {
           Position newPos = calNewPosition(direction);
           if(isValidMove(newPos))
           {
               pos = newPos;
           }
       }

        
    }; 

#endif
