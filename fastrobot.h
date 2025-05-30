#ifndef FASTROBOT_H
#define FASTROBOT_H

#include "robot.h"
#include "battlefield.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

// can look bigger (5x5) and only move 2 direction (left and right )
class FastRobot: public Robot, public SeeingRobot, public MovingRobot
{
    private:
        Battlefield* battlefield;   // to access robot position

        bool hasLooked;
        bool hasMoved;

    public:
        // constructor
        ScoutRobot(const std::string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : Robot(name, startX, startY, w, h,battlefield), battlefield(battlefield)
        {
            battlefield -> placeRobot(this, startX, startY);// put inside battlefield and set initial position
            resetTurnFlags();
        }

        void resetTurnFlags()
        {
            hasLooked = false;
            hasMoved = false;
        }

        // each round(step) action execution, cannot repeat, follow look-move
        void performTurn()
        {
            resetTurnFlags();

            // 1. look
            if (!hasLooked)
            {
                int lookX = (rand()%3) -1;
                int lookY = (rand()%3) -1;
                look(lookX, lookY);
                hasLooked = true;
            }

            // 2. Move
            if (!hasMoved)
            {
                int direction = rand()%2;
                move(direction);
                hasMoved = true;
            }
        }



       //look around in the center position
       virtual void look(int x, int y)
       {
           int centerX = pos.robotPositionX + x;   // center x and y
           int centerY = pos.robotPositionY + y;

           std::cout << name << " is looking at area centered at (" << centerX << ", " << centerY << ")."<< endl;

           for (int i = -2; i <= 2; ++i)   // check surrounding position
           {
               for (int j = -2; j <= 2; ++j)
               {
                   int lookX = centerX + i;
                   int lookY = centerY + j;

                   if (lookX >=0 && lookX < battlefield ->getWidth() &&     //// check if the position is inside battlefield
                       lookY >=0 && lookY < battlefield ->getHeight())
                   {
                       Robot* r = battlefield -> getRobotAt(lookX, lookY);
                       if (r!= nullptr)
                       {
                           std::cout << " - Robot " << r -> getName() << " at (" << lookX << ", " << lookY << ")" << endl;
                       }
                   }
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
           return (p.robotPositionX >= 0 && p.robotPositionX < battlefield ->getWidth() &&
                   p.robotPositionY >= 0 && p.robotPositionY < battlefield ->getHeight());
       }

       virtual void move(int direction) override
       {
           Position newPos = calNewPosition(direction);
           if(isValidMove(newPos))
           {
               battlefield -> removeRobot(this); //remove the old position
               battlefield -> placeRobot(this, newPos.robotPositionX, newPos.robotPositionY); //place the new position
               setPosition(newPos.robotPositionX, newPos.robotPositionY);
               std::cout << name << " moved to (" << getX() << ", " << getY() << ")." << endl;
           }
           else
           {
               std::cout << name << " invalid move, keep position (" << getX() << ", " << getY() << ")." << endl;
           }
           }
       }



    };

#endif
