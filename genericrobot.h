/**********|**********|**********|
 Program: genericrobot.h
 Course: OOPDS
 Trimester: 2510
 Name: Bianca Lau Ying Xuan
 ID: 242UC2426R
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: BIANCA.LAU.YING@student.mmu.edu.my
 Phone: 010-2752246
  **********|**********|**********/

#ifndef GENERICROBOT_H
#define GENERICROBOT_H

#include "robot.h"
#include "battlefield.h"
#include "Constants.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class GenericRobot: public virtual Robot,
                    public virtual ThinkingRobot,
                    public virtual SeeingRobot,
                    public virtual ShootingRobot,
                    public virtual MovingRobot
{
    private:
        Battlefield* battlefield;   // to access robot position

        bool hasThought;
        bool hasLooked;
        bool hasFired;
        bool hasMoved;

        // Add upgrade tracking variables
        string currentSeeingUpgrade;
        string currentMovingUpgrade;
        string currentShootingUpgrade;
        // Only keep the basic upgrade types here
        vector<string> availableUpgrades = {
            "TrackBot", "ScoutBot", "SemiAutoBot", "ThirtyShotBot", "LongShotBot", "JumpBot", "HideBot"
        };

    public:
        // Add these static member declarations
        static const vector<string> firstUpgrades;
        static const vector<string> secondUpgrades;
        static const vector<string> thirdUpgrades;

        // constructor
        GenericRobot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : Robot(name, startX, startY, w, h), battlefield(battlefield)
        {
            battlefield -> placeRobot(this, startX, startY);// put inside battlefield and set initial position
            resetTurnFlags();
        }

        GenericRobot()
        : Robot("Default", 0, 0, 1, 1), battlefield(nullptr)
        {
            // Set other member defaults as needed
            resetTurnFlags();
        }

        virtual void displayStats() const {
            cout << "Robot Name: " << name << endl;
            cout << "Position: (" << pos.robotPositionX << ", " << pos.robotPositionY << ")" << endl;
            cout << "Lives: " << lives << endl;
            cout << "Shells: " << shells << endl;
            cout << "Alive: " << (alive ? "Yes" : "No") << endl;
            // Output upgrades if selected
            cout << "Current Seeing Upgrade: " 
                 << (currentSeeingUpgrade.empty() ? "None" : currentSeeingUpgrade) << endl;
            cout << "Current Moving Upgrade: " 
                 << (currentMovingUpgrade.empty() ? "None" : currentMovingUpgrade) << endl;
            cout << "Current Shooting Upgrade: " 
                 << (currentShootingUpgrade.empty() ? "None" : currentShootingUpgrade) << endl;
        }

         
        Battlefield* getBattlefield() const { return battlefield; }
        void setBattlefield(Battlefield* bf) { battlefield = bf; }
        
        void resetTurnFlags()
        {
            hasThought = false;
            hasLooked = false;
            hasFired = false;
            hasMoved = false;
        }

        // each round(step) action execution, cannot repeat, follow think-look-fire-move
        void performTurn()
        {
            resetTurnFlags();

            // 1. think
            if (!hasThought)
            {
                think();
                hasThought=true;
                if (!alive)       // if no shell will self destruct
                {
                   return;
                }
            }

            // 2. look
            if (!hasLooked)
            {
                int lookX = (rand()%3) -1;
                int lookY = (rand()%3) -1;
                look(lookX, lookY);
                hasLooked = true;
            }

            // 3. Fire
            if (!hasFired)
            {
                int fireX, fireY;
                do
                {
                    fireX = (rand()%3) -1;
                    fireY = (rand()%3) -1;
                }
                while (fireX == 0 && fireY == 0);
                fire(fireX, fireY);
                hasFired = true;
            }

            // 4. Move
            if (!hasMoved)
            {
                int direction = rand()%8;
                move(direction);
                hasMoved = true;
            }
        }

        virtual void think() override       // if shell runs out, robot will self destruct
        {
            if (shells <= 0)
            {
               cout << name << " has no shells left. Self-destructed."<< endl ;
               lives--;

               if (lives >0)
               {
                   respawnRandom(battlefield);
               }
               else
               {
                   alive = false;
                   cout << name << "is permanently dead." << endl;
               }
            }
        }

        //look around in the center position
       virtual void look(int x, int y)
       {
           int centerX = pos.robotPositionX + x;   // center x and y
           int centerY = pos.robotPositionY + y;

           cout << name << " is looking at area centered at (" << centerX << ", " << centerY << ")." << endl;

           for (int i = -1; i <= 1; ++i)   // check surrounding position
           {
               for (int j = -1; j <= 1; ++j)
               {
                   int lookX = centerX + i;
                   int lookY = centerY + j;

                   if (lookX >=0 && lookX < battlefield ->getWidth() &&     //// check if the position is inside battlefield
                       lookY >=0 && lookY < battlefield ->getWidth())
                   {
                       Robot* r = battlefield -> getRobotAt(lookX, lookY);
                       if (r!= nullptr)
                       {
                           cout << " - Robot " << r -> getName() << " at (" << lookX << ", " << lookY << ")" << endl;
                       }
                   }
               }
           }
       }


        // shoot the robot in the direction of x, y
        virtual void fire(int x, int y) override
       {
           if (shells <=0)
           {
               return;      // no shells left, cannot shoot
           }

          if (x < -1 || x > 1 || y < -1 || y > 1 || (x == 0 && y == 0))
          {
              return;                 //cannot shoot at self and out of range
          }

           shells--;                  // reduce shells by 1 when used

           // calculate target position
           int targetX = pos.robotPositionX + x;
           int targetY = pos.robotPositionY + y;

           // check if target position is inside battlefield
           if (targetX < 0 || targetX >= battlefield -> getWidth() ||
               targetY < 0 || targetY >= battlefield -> getHeight())
               {
                   return;
               }

            Robot* target = battlefield -> getRobotAt(targetX,targetY);
            if (target != nullptr && target -> isAlive())        // robot not null and alive
            {
                if(rand() % 100 < 70)
                {
                    cout << name << " successfully hit " << target -> getName() << "." << endl;
                    target -> takeDamage(name, battlefield);
                }
                else
                {
                    cout << name << " missed the shot at " << target -> getName() << "." << endl;
                }
            } else
            {
                cout << name << " fired at (" << targetX << ", " << targetY << ") but no target." << endl;    //when the target is null and the target robot not alive
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
           return (p.robotPositionX >= 0 && p.robotPositionX < battlefield ->getWidth() &&
                   p.robotPositionY >= 0 && p.robotPositionY < battlefield ->getHeight() &&
                   battlefield -> getRobotAt(p.robotPositionX,p.robotPositionY)== nullptr);
       }

       virtual void move(int direction) override
       {
           Position newPos = calNewPosition(direction);
           if(isValidMove(newPos))
           {
               battlefield -> removeRobot(this); //remove the old position
               battlefield -> placeRobot(this, newPos.robotPositionX, newPos.robotPositionY); //place the new position
               setPosition(newPos.robotPositionX, newPos.robotPositionY);
               cout << name << " moved to (" << getX() << ", " << getY() << ")." << endl;
           }
           else
           {
               cout << name << " invalid move, keep position (" << getX() << ", " << getY() << ")." << endl;
           }
       }
       
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

    

};



#endif
