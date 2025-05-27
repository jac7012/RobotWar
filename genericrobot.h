#ifndef GENERICROBOT_H
#define GENERICROBOT_H

#include "newrobot.h"
#include "Battlefield.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>



class GenericRobot: public Robot, public ThinkingRobot,  public SeeingRobot, public ShootingRobot, public MovingRobot
{
    public:
        // constructor
        GenericRobot(const std::string& name, int startX, int startY, int w, int h)
        : Robot(name, startX, startY, w, h) 
        {   
            pos.robotPositionX = startX;
            pos.robotPositionY = startY;
        }


        virtual void think() override 
        { 
            if (shells <= 0) 
            {
            std::cout << name << " has no shells left. Self-destructed!\n";
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
                   bool inBattlefield = (lookX >= 0 && lookX < battlefieldWidth &&
                               lookY >= 0 && lookY < battlefieldHeight);
                   
               }
           }
           /*no cout surrounding robot*/
       }


        // shoot the robot
        virtual void fire(int x, int y) override
          // shoot in the direction of x, y
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

               /*
               Robot* target = battlefield->getRobotAt(targetX, targetY);
               if (target != nullptr && target->isLives())
               {
                   target->takeDamage(damage);
                   std::cout << name << " hit " << target->getName() << " for " << damage << " damage.\n";
               }

               */
           } 
        }

    
       Position calNewPosition(int direction)   // calculate new position based on direction
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
