#ifndef HIDEBOT_H
#define HIDEBOT_H

#include "GenericRobot.h"

class HideBot : public GenericRobot {
private:
    int hideCount;
    
public:
    HideBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h), hideCount(3) {
        chooseMovingUpgrade("HideBot");
    }

    void hide()  {
        if (hideCount > 0) {
            hidden = true;
            hideCount--;
            cout << name << " is now hidden! (" << hideCount << " hides remaining)\n";
        }
    }

    void displayStats()  {
        GenericRobot::displayStats();
        cout << "Upgrade: HideBot | Hides left: " << hideCount << endl;
    }
};

#endif
