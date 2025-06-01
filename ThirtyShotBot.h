#pragma once
/**********|**********|**********|
 Program: ThirtyShotBot.h
 Course: OOPDS
 Trimester: 2510
 Name: Lim E Jac
 ID: 242UC245BG
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: LIM.E.JAC@student.mmu.edu.my
 Phone: 017-7026113
 **********|**********|**********/

#include "genericrobot.h"
#include "battlefield.h"
#include "Constants.h"
#include "TrackBot.h"
#include "LongShotBot.h"
#include "SemiAutoBot.h"
#include "HideBot.h"
#include "ScoutBot.h"
#include "JumpBot.h"

class ThirtyShotBot : public virtual GenericRobot , public virtual ShootingRobot {
public:
    ThirtyShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield) {
        chooseShootingUpgrade("ThirtyShotBot");
        shells = 30; // Override to 30 shells
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Type: ThirtyShotBot | Shells: " << shells << "/30" << endl;
    }
};
