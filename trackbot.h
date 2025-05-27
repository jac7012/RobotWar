#ifndef TRACKBOT_H
#define TRACKBOT_H

#include "GenericRobot.h"
#include <map>

class TrackBot : public GenericRobot {
private:
    int trackers;
    map<string, Position> trackedRobots;
    
public:
    TrackBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h), trackers(3) {
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

#endif
