#ifndef SEMIAUTOBOT_H
#define SEMIAUTOBOT_H

#include "GenericRobot.h"

class SemiAutoBot : public GenericRobot {
public:
    SemiAutoBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h) {
        chooseShootingUpgrade("SemiAutoBot");
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        if (shells <= 0) return;
        
        if (x < -1 || x > 1 || y < -1 || y > 1 || (x == 0 && y == 0)) return;
        
        shells--;
        int targetX = pos.robotPositionX + x;
        int targetY = pos.robotPositionY + y;
        
        if (targetX < 0 || targetX >= fieldWidth ||
            targetY < 0 || targetY >= fieldHeight)
            return;

        cout << name << " firing 3-shot burst!\n";
        for (int i = 0; i < 3; i++) {
            if (rand() % 100 < 70) {
                int damage = rand() % 71;
                Robot* target = battlefield->getRobotAt(targetX, targetY);
                if (target != nullptr && target->isLives()) {
                    target->takeDamage(damage);
                    cout << "Hit " << target->getName() 
                         << " with burst shot for " << damage << " damage.\n";
                }
            }
        }
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: SemiAutoBot | 3-shot burst" << endl;
    }
};

#endif
