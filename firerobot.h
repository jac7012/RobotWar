#ifndef FIREROBOT_H
#define FIREROBOT_H
#include "robot.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

class FireRobot: public ShootingRobot
{
    public:
        // constructor
        FireRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}
        
        // shoot the robot
        void fire(int x, int y) override
        {
            ShootingRobot::fire(x, y);
        }
        
};


#endif