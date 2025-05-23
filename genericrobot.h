#ifndef GENERICROBOT_H
#define GENERICROBOT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>


class genericRobot: public MovingRobot, public ShootingRobot, public SeeingRobot, public ThinkingRobot
{
    public:
        // constructor
        genericRobot(const std::string& name, int x, int y, int w, int h)
        : MovingRobot(name, x, y, w, h), 
        ShootingRobot(name, x, y, w, h),
        SeeingRobot(name, x, y, w, h), 
        ThinkingRobot(name, x, y, w, h) {}
        
        // move the robot
        void move(int direction) override
        {
            MovingRobot::move(direction);
        }
        
        // shoot the robot
        void fire(int x, int y) override
        {
            ShootingRobot::fire(x, y);
        }

        // look around the robot
        void look(int x, int y) override
        {
            SeeingRobot::look(x, y);
        }
        
        // think for the robot
        void think(int x, int y) override
        {
            ThinkingRobot::think(x, y);
        }
};

#endif