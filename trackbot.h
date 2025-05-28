#ifndef TRACKBOT_H
#define TRACKBOT_H

#include "GenericRobot.h"
#include "Battlefield.h"
#include "JumpBot.h"
#include "TrackBot.h"
#include "ThirtyShotBot.h"
#include "SemiAutoBot.h"
#include "LongShotBot.h"
#include <map>

class TrackBot : public virtual GenericRobot {
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

// TrackBot + Hide
class TrackHideBot : public virtual TrackBot, public virtual HideBot {
public:
    TrackHideBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), HideBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); HideBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + Hide" << endl;
        TrackBot::displayStats();
        HideBot::displayStats();
    }
};

// TrackBot + Jump
class TrackJumpBot : public virtual TrackBot, public virtual JumpBot {
public:
    TrackJumpBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), JumpBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); JumpBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + Jump" << endl;
        TrackBot::displayStats();
        JumpBot::displayStats();
    }
};

// TrackBot + LongShot
class TrackLongShotBot : public virtual TrackBot, public virtual LongShotBot {
public:
    TrackLongShotBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), LongShotBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); LongShotBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + LongShot" << endl;
        TrackBot::displayStats();
        LongShotBot::displayStats();
    }
};

// TrackBot + SemiAuto
class TrackSemiAutoBot : public virtual TrackBot, public virtual SemiAutoBot {
public:
    TrackSemiAutoBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); SemiAutoBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + SemiAuto" << endl;
        TrackBot::displayStats();
        SemiAutoBot::displayStats();
    }
};

// TrackBot + ThirtyShot
class TrackThirtyShotBot : public virtual TrackBot, public virtual ThirtyShotBot {
public:
    TrackThirtyShotBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); ThirtyShotBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + ThirtyShot" << endl;
        TrackBot::displayStats();
        ThirtyShotBot::displayStats();
    }
};
//2nd upgrade
// TrackBot + Hide + LongShot
class TrackHideLongShotBot : public virtual TrackBot, public virtual HideBot, public virtual LongShotBot {
public:
    TrackHideLongShotBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), HideBot(name, x, y, w, h), LongShotBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); HideBot::think(); LongShotBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + Hide + LongShot" << endl;
        TrackBot::displayStats();
        HideBot::displayStats();
        LongShotBot::displayStats();
    }
};

// TrackBot + Hide + SemiAuto
class TrackHideSemiAutoBot : public virtual TrackBot, public virtual HideBot, public virtual SemiAutoBot {
public:
    TrackHideSemiAutoBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), HideBot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); HideBot::think(); SemiAutoBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + Hide + SemiAuto" << endl;
        TrackBot::displayStats();
        HideBot::displayStats();
        SemiAutoBot::displayStats();
    }
};

// TrackBot + Hide + ThirtyShot
class TrackHideThirtyShotBot : public virtual TrackBot, public virtual HideBot, public virtual ThirtyShotBot {
public:
    TrackHideThirtyShotBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), HideBot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); HideBot::think(); ThirtyShotBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + Hide + ThirtyShot" << endl;
        TrackBot::displayStats();
        HideBot::displayStats();
        ThirtyShotBot::displayStats();
    }
};

// TrackBot + Jump + LongShot
class TrackJumpLongShotBot : public virtual TrackBot, public virtual JumpBot, public virtual LongShotBot {
public:
    TrackJumpLongShotBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), JumpBot(name, x, y, w, h), LongShotBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); JumpBot::think(); LongShotBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + Jump + LongShot" << endl;
        TrackBot::displayStats();
        JumpBot::displayStats();
        LongShotBot::displayStats();
    }
};

// TrackBot + Jump + SemiAuto
class TrackJumpSemiAutoBot : public virtual TrackBot, public virtual JumpBot, public virtual SemiAutoBot {
public:
    TrackJumpSemiAutoBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), JumpBot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); JumpBot::think(); SemiAutoBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + Jump + SemiAuto" << endl;
        TrackBot::displayStats();
        JumpBot::displayStats();
        SemiAutoBot::displayStats();
    }
};

// TrackBot + Jump + ThirtyShot
class TrackJumpThirtyShotBot : public virtual TrackBot, public virtual JumpBot, public virtual ThirtyShotBot {
public:
    TrackJumpThirtyShotBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), JumpBot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); JumpBot::think(); ThirtyShotBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + Jump + ThirtyShot" << endl;
        TrackBot::displayStats();
        JumpBot::displayStats();
        ThirtyShotBot::displayStats();
    }
};

// TrackBot + LongShot + Hide
class TrackLongShotHideBot : public virtual TrackBot, public virtual LongShotBot, public virtual HideBot {
public:
    TrackLongShotHideBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), LongShotBot(name, x, y, w, h), HideBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); LongShotBot::think(); HideBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + LongShot + Hide" << endl;
        TrackBot::displayStats();
        LongShotBot::displayStats();
        HideBot::displayStats();
    }
};

// TrackBot + LongShot + Jump
class TrackLongShotJumpBot : public virtual TrackBot, public virtual LongShotBot, public virtual JumpBot {
public:
    TrackLongShotJumpBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), LongShotBot(name, x, y, w, h), JumpBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); LongShotBot::think(); JumpBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + LongShot + Jump" << endl;
        TrackBot::displayStats();
        LongShotBot::displayStats();
        JumpBot::displayStats();
    }
};

// TrackBot + SemiAuto + Hide
class TrackSemiAutoHideBot : public virtual TrackBot, public virtual SemiAutoBot, public virtual HideBot {
public:
    TrackSemiAutoHideBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), HideBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); SemiAutoBot::think(); HideBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + SemiAuto + Hide" << endl;
        TrackBot::displayStats();
        SemiAutoBot::displayStats();
        HideBot::displayStats();
    }
};

// TrackBot + SemiAuto + Jump
class TrackSemiAutoJumpBot : public virtual TrackBot, public virtual SemiAutoBot, public virtual JumpBot {
public:
    TrackSemiAutoJumpBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), JumpBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); SemiAutoBot::think(); JumpBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + SemiAuto + Jump" << endl;
        TrackBot::displayStats();
        SemiAutoBot::displayStats();
        JumpBot::displayStats();
    }
};

// TrackBot + ThirtyShot + Hide
class TrackThirtyShotHideBot : public virtual TrackBot, public virtual ThirtyShotBot, public virtual HideBot {
public:
    TrackThirtyShotHideBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), HideBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); ThirtyShotBot::think(); HideBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + ThirtyShot + Hide" << endl;
        TrackBot::displayStats();
        ThirtyShotBot::displayStats();
        HideBot::displayStats();
    }
};

// TrackBot + ThirtyShot + Jump
class TrackThirtyShotJumpBot : public virtual TrackBot, public virtual ThirtyShotBot, public virtual JumpBot {
public:
    TrackThirtyShotJumpBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), TrackBot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), JumpBot(name, x, y, w, h) {}
    void think() override { TrackBot::think(); ThirtyShotBot::think(); JumpBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: Track + ThirtyShot + Jump" << endl;
        TrackBot::displayStats();
        ThirtyShotBot::displayStats();
        JumpBot::displayStats();
    }
};

#endif
