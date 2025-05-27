#ifndef JUMPBOT_H
#define JUMPBOT_H

#include "GenericRobot.h"
#include "Battlefield.h"

class JumpBot : public GenericRobot {
private:
    int jumpCount;
    
public:
    JumpBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h), jumpCount(3) {
        chooseMovingUpgrade("JumpBot");
    }

    void jump(Battlefield& battlefield, int targetX, int targetY) override {
        if (jumpCount > 0) {
            if (targetX >= 0 && targetX < fieldWidth && 
                targetY >= 0 && targetY < fieldHeight) {
                Position newPos;
                newPos.robotPositionX = targetX;
                newPos.robotPositionY = targetY;
                
                if (battlefield.isValidMove(newPos)) {
                    pos = newPos;
                    jumpCount--;
                    cout << name << " jumped to (" << targetX << "," << targetY 
                         << ") (" << jumpCount << " jumps remaining)\n";
                }
            }
        }
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: JumpBot | Jumps left: " << jumpCount << endl;
    }
};

#endif
