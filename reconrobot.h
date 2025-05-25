#ifndef reconrobot_h
#define reconrobot_h
#include newrobot.h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

class ReconRobot: public lookingRobot, public shootingRobot, public movingRobot
{
    public:
        // constructor
        ReconRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}
        
        // move the robot
        void move(int direction) override
        {
            Robot::move(direction);
        }
        
        // shoot the robot
        void fire(int x, int y) override
        {
            Robot::fire(x, y);
        }
        
        // look around the robot
        void look(int x, int y) override
        {
            Robot::look(x, y);
        }
        
};

#endif