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
#include "Battlefield.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

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
       int health;         // health of the robot (0-100)
       bool alive;         // is the robot alive
       int shells;         // number of shells
       int upgradeLevel;   // upgrade level of the robot
       int battlefieldWidth;
       int battlefieldHeight;

    public:
       //constructor for set initial values
       Robot(const std::string& name, int startX, int startY, int w, int h)
       {
          this->name = name;
          this->pos.robotPositionX = startX;
          this->pos.robotPositionY = startY;
          this->lives = 3;
          this->health = 100;
          this->shells = 10;
          this->upgradeLevel = 0;
          this->battlefieldWidth = w;
          this->battlefieldHeight = h;
          this->alive = true;
       }
       
       Position getPosition() const
       {   
           return pos;
       }

       std::string getName() const
       {   
           return name;
       }

       int getLives() const
       {
           return lives;
       }

       int getHealth() const
       {   
           return health;
       }    

       bool isLives() const
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

       //reduce health by damage
       void takeDamage(int damage)
       {
           health -= damage;       // subtract damage from health
           if (health <= 0)
           {   
               lives--;            // reduce lives by 1 if health < 0
               if (lives > 0)
               {
                   respawnRandom();
               } 
               else
               {
                   alive = false;
                   health = 0;
               }
           }
       }

       // respawn robot randomly
       void respawnRandom()
       {
           health = 100;
           shells = 10;
           pos= findRandomEmptyPosition();
       }
    /*   
       //write in battlefield.h

       struct Position
       {
           int robotPositionX;
           int robotPositionY;
       }

       bool isInBounds(int x, int y) const
       {   
          return (x >= 0 && x < width && y >= 0 && y < height); 
       }
    
       bool isPositionEmpty(int x, int y) const
       {   
       return isInbounds(x,y) && grid[y][x] == '.'; 
       



        Position findRandomEmptyPosition()
       {
           Position Pos;
           do
           {
               newPos.robotPositionX = rand() % width;
               newPos.robotPositionY = rand() % height;
           } 
           while (!isPositionEmpty(robotPositionX, robotPositionY));
              
           return pos;
       }

       */
};

// inherit from Robot class
class MovingRobot: virtual public Robot
{
    protected:
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
    
    public:
       //constructor
       MovingRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}

       virtual void move(int direction) 
       {
           Position newPos = calNewPosition(direction);
           if(isValidMove(newPos))
           {
               pos = newPos;
           }
       }
       
};

// inherit from Robot class
class ShootingRobot: virtual public Robot
{
    public:
       //constructor
       ShootingRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}

       virtual void fire(int x, int y)   // shoot in the direction of dx, dy
       { 
           if (shells <=0) return;  // no shells left, cannot shoot

           if (x==0 && y==0) return; //cannot shoot at self
           shells--;                  // reduce shells by 1 when used

           // calculate target position
           int targetX = pos.robotPositionX + x;
           int targetY = pos.robotPositionY + y;

              // check if target position is inside battlefield
           if (targetX < 0 || targetX >= battlefieldWidth ||
              targetY < 0 || targetY >= battlefieldHeight)
               return; 
/*************************************************   */
           if(rand() % 100 < 70) // 70% chance to hit
           {
               int damage = rand() % 71; //0-70%

               std::cout << "Hit! Damage: " << damage << std::endl;
           } else
           {
               std::cout << "Missed!" << std::endl;
           }
               

       } 
};

// inherit from Robot class
class SeeingRobot: virtual public Robot
{
    public:
    // constructor
       SeeingRobot(const std::string& name, int x, int y, int w, int h)
       : Robot(name, x, y, w, h) {}

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
       }

};

// inherit from Robot class
class ThinkingRobot: virtual public Robot
{
    public:
    // constructor
       ThinkingRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}

       virtual void think(int x, int y) 
       {
        private:

           int calDirectiom(int dirx, int diry) // calculate direction to move
           {
               if (dirx > 0 && diry > 0) return 2; // Right up
               else if (dirx < 0 && diry > 0) return 1; // Left up
               else if (dirx > 0 && diry < 0) return 7; // Right down
               else if (dirx < 0 && diry < 0) return 6; // Left down
               else if (dirx > 0) return 4; // Right
               else if (dirx < 0) return 3; // Left
               else if (diry > 0) return 5; // Down
               else if (diry < 0) return 0; // Up

               return -1; 
           }   
        public:
           if (health < 50)    //if healsth less than 50, move to safe place(0,0
           {
            int safeX=0;
            int safeY=0; 
            
            int moveDirX= safeX - pos.robotPositionX ;  
            int moveDirY= safeY - pos.robotPositionY;

            int moveDir = calDirectiom( dirx, diry); // calculate direction to move
            move(moveDir); 

           } else
           { fire(enemyRelX, enemyRelY); } // fire at enemy if health > 50
         
       }
};


#endif