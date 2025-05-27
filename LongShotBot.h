#ifndef LONGSHOTBOT_H
#define LONGSHOTBOT_H

#include "GenericRobot.h"

class LongShotBot : public GenericRobot {
public:
    LongShotBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h) {
        chooseShootingUpgrade("LongShotBot");
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        if (shells <= 0) return;
        
        if (abs(x) + abs(y) > 3) {
            cout << "Target out of range for LongShotBot!\n";
            return;
        }

        shells--;
        int targetX = pos.robotPositionX + x;
        int targetY = pos.robotPositionY + y;
        
        if (targetX < 0 || targetX >= fieldWidth ||
            targetY < 0 || targetY >= fieldHeight)
            return;

        if (rand() % 100 < 70) {
            int damage = rand() % 71;
            Robot* target = battlefield->getRobotAt(targetX, targetY);
            if (target != nullptr && target->isLives()) {
                target->takeDamage(damage);
                cout << name << " hit " << target->getName() 
                     << " from long range \n";
            }
        }
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: LongShotBot | Range: 3 units" << endl;
    }
};

#endif
