#ifndef RECONROBOT_H
#define RECONROBOT_H

#include "newrobot.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

class ReconRobot : public SeeingRobot, public ShootingRobot, public MovingRobot {
public:
    ReconRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}

    void move(int direction) override {
        std::cout << name << " moves in direction " << direction << ".\n";
    }

    void fire(int x, int y) override {
        std::cout << name << " fires at (" << x << "," << y << ").\n";
    }

    void look(int x, int y) override {
        std::cout << name << " looks at (" << x << "," << y << ").\n";
    }

    bool canUpgrade() const override {
        return false;
    }

    void upgrade(const std::string& upgradeType) override {
        std::cout << name << " cannot upgrade.\n";
    }
};

#endif
