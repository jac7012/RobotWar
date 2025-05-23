#ifndef SUPPORTROBOT_H
#define SUPPORTROBOT_H
#include "robot.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

class SupportRobot: public ThinkingRobot, public SeeingRobot
{
    public:
        // constructor
        SupportRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}
        
        // think for the robot
        void think(int x, int y) override
        {
            Robot::think(x, y);
        }
        
        // look around the robot
        void look(int x, int y) override
        {
            Robot::look(x, y);
        }
}; 

#endif