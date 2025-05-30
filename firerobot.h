#ifndef FIREROBOT_H
#define FIREROBOT_H

#include "newrobot.h"
#include "Battlefield.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

class FireRobot : public ShootingRobot {
public:
    FireRobot(const std::string& name, int x, int y, int w, int h)
        : Robot(name, x, y, w, h) {}

    virtual void fire(int x, int y) override {
        if (shells <= 0) return;
        if (x < -1 || x > 1 || y < -1 || y > 1 || (x == 0 && y == 0)) return;
        shells--;

        int targetX = pos.robotPositionX + x;
        int targetY = pos.robotPositionY + y;

        if (targetX < 0 || targetX >= fieldWidth || targetY < 0 || targetY >= fieldHeight)
            return;

        if (rand() % 100 < 70) {
            int damage = rand() % 71;
        }
    }

    bool canUpgrade() const override {
        return false;
    }

    void upgrade(const std::string& upgradeType) override {
        std::cout << name << " cannot upgrade.\n";
    }
};

#endif
