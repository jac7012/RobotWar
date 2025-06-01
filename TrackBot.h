/**********|**********|**********|
 Program: TrackBot.h
 Course: OOPDS
 Trimester: 2510
 Name: Lim E Jac
 ID: 242UC245BG
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: LIM.E.JAC@student.mmu.edu.my
 Phone: 017-7026113
 **********|**********|**********/

#pragma once

#include "genericrobot.h"
#include "battlefield.h"
#include "Constants.h"
#include "HideBot.h"
#include "ScoutBot.h"
#include "JumpBot.h"
#include <map>

class TrackBot : public virtual GenericRobot , public virtual SeeingRobot {
private:
    int trackers;
    map<string, Position> trackedRobots;
    
public:
    TrackBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield), trackers(3) {
        chooseSeeingUpgrade("TrackBot");
    }

    void track(Battlefield* battlefield, const string& targetName) {
        if (trackers > 0) {
            Robot* target = battlefield->getRobotByName(targetName);
            if (target && target != this) {
                trackedRobots[targetName] = target->getPosition();
                trackers--;
                cout << "Tracking " << targetName << "! (" 
                     << trackers << " trackers remaining)\n";
            }
        }
    }

    void updateTrackedPositions(Battlefield* battlefield) {
        for (auto& entry : trackedRobots) {
            Robot* target = battlefield->getRobotByName(entry.first);
            if (target) {
                entry.second = target->getPosition();
            }
        }
    }

    virtual void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: TrackBot | Trackers left: " << trackers << endl;
        if (!trackedRobots.empty()) {
            cout << "Currently tracking:\n";
            for (const auto& entry : trackedRobots) {
                cout << "  " << entry.first << " at (" 
                     << entry.second.robotPositionX << "," 
                     << entry.second.robotPositionY << ")\n";
            }
        }
    }
};

// TrackBot + Hide
// (moved to TrackHideBot.h)
// TrackBot + Jump
// (moved to TrackJumpBot.h)
// TrackBot + LongShot
// (moved to TrackLongShotBot.h)
// TrackBot + SemiAuto
// (moved to TrackSemiAutoBot.h)
// TrackBot + ThirtyShot
// (moved to TrackThirtyShotBot.h)
// 2nd upgrade
// TrackBot + Hide + LongShot
// (moved to TrackHideLongShotBot.h)
// TrackBot + Hide + SemiAuto
// (moved to TrackHideSemiAutoBot.h)
// TrackBot + Hide + ThirtyShot
// (moved to TrackHideThirtyShotBot.h)
// TrackBot + Jump + LongShot
// (moved to TrackJumpLongShotBot.h)
// TrackBot + Jump + SemiAuto
// (moved to TrackJumpSemiAutoBot.h)
// TrackBot + Jump + ThirtyShot
// (moved to TrackJumpThirtyShotBot.h)
// TrackBot + LongShot + Hide
// (moved to TrackLongShotHideBot.h)
// TrackBot + LongShot + Jump
// (moved to TrackLongShotJumpBot.h)
// TrackBot + SemiAuto + Hide
// (moved to TrackSemiAutoHideBot.h)
// TrackBot + SemiAuto + Jump
// (moved to TrackSemiAutoJumpBot.h)
// TrackBot + ThirtyShot + Hide
// (moved to TrackThirtyShotHideBot.h)
// TrackBot + ThirtyShot + Jump
// (moved to TrackThirtyShotJumpBot.h)
