#ifndef FIREROBOT_H
#define FIREROBOT_H

#include "robot.h"
#include "battlefield.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

//can shoot anywhere in the battlefield

class FireRobot: public Robot, public ShootingRobot
{
    private:
        Battlefield* battlefield;   // to access robot position

        bool hasFired;

    public:

        FireRobot(const std::string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : Robot(name, startX, startY, w, h,battlefield), battlefield(battlefield)
        {
            battlefield -> placeRobot(this, startX, startY);// put inside battlefield and set initial position
            resetTurnFlags();
        }

        void resetTurnFlags()
        {
            hasFired = false;
        }

        // each round(step) action execution, cannot repeat, follow fire only
        void performTurn()
        {
            resetTurnFlags();

            // 1. Fire
            if (!hasFired)
            {
                fire(0,0);      // pass parameters, but not actually use
                hasFired = true;
            }
        }


        // shoot the robot
         virtual void fire(int x, int y) override

       {
           if (shells <=0)
           return;  // no shells left, cannot shoot

           shells--;

          int targetX, targetY;

          do
          {
              targetX = rand() % battlefield -> getWidth();
              targetY = rand() % battlefield-> getHeight();
          }
          while (targetX == pos.robotPositionX && targetY == pos.robotPositionY);  // shoot at a random position and cannot shoot at self


          Robot* target = battlefield -> getRobotAt(targetX,targetY);

          if (target != nullptr && target -> isAlive())        // robot not null and alive
          {
              if(rand() % 100 < 70)
              {
                  std::cout << name << " successfully hit " << target -> getName() << "." << endl;
                  target -> takeDamage(name, battlefield);
              }
              else
              {
                  std::cout << name << " missed the shot at " << target -> getName() << "." << endl;
              }
          }
          else
          {
              std::cout << name << " fired at (" << targetX << ", " << targetY << ") but no target." << endl;    //when the target is null and the target robot not alive
          }
        }

};




    bool canUpgrade() const override {
        return false;
    }

    void upgrade(const std::string& upgradeType) override {
        std::cout << name << " cannot upgrade.\n";
    }
};

#endif
