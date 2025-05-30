/**********|**********|**********|
 Program: hibeBot.h
 Course: OOPDS
 Trimester: 2510
 Name: Lim E Jac
 ID: 242UC245BG
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: LIM.E.JAC@student.mmu.edu.my
 Phone: 017-7026113
 **********|**********|**********/

#ifndef HIDEBOT_H
#define HIDEBOT_H

#include "GenericRobot.h"
#include "LongShotBot.h"
#include "SemiAutoBot.h"
#include "ThirtyShotBot.h"
#include "ScoutBot.h"
#include "TrackBot.h"
#include "JumpBot.h"

class HideBot : public virtual GenericRobot {
private:
    int hideCount;
    bool hidden = false; // Indicates if the bot is currently hidden
public:
    HideBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield), hideCount(3) {
        chooseMovingUpgrade("HideBot");
    }

    void hide()  {
        if (hideCount > 0) {
            hidden = true;
            hideCount--;
            cout << name << " is now hidden! (" << hideCount << " hides remaining)\n";
        }
    }

    virtual void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: HideBot | Hides left: " << hideCount << endl;
    }
};

// Hide + LongShot
class HideLongShotBot : public virtual HideBot, public virtual LongShotBot {
public:
    HideLongShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + LongShot" << endl;
        HideBot::displayStats();
        LongShotBot::displayStats();
    }
};

// Hide + SemiAuto
class HideSemiAutoBot : public virtual HideBot, public virtual SemiAutoBot {
public:
    HideSemiAutoBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + SemiAuto" << endl;
        HideBot::displayStats();
        SemiAutoBot::displayStats();
    }
};

// Hide + ThirtyShot
class HideThirtyShotBot : public virtual HideBot, public virtual ThirtyShotBot {
public:
    HideThirtyShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + ThirtyShot" << endl;
        HideBot::displayStats();
        ThirtyShotBot::displayStats();
    }
};

// Hide + Track
class HideTrackBot : public virtual HideBot, public virtual TrackBot {
public:
    HideTrackBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + Track" << endl;
        HideBot::displayStats();
        TrackBot::displayStats();
    }
};

// Hide + Scout
class HideScoutBot : public virtual HideBot, public virtual ScoutBot {
public:
    HideScoutBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + Scout" << endl;
        HideBot::displayStats();
        ScoutBot::displayStats();
    }
};

// Hide + LongShot + Scout
class HideLongShotScoutBot : public HideBot, public LongShotBot, public ScoutBot {
public:
    HideLongShotScoutBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + LongShot + Scout" << endl;
        HideBot::displayStats();
        LongShotBot::displayStats();
        ScoutBot::displayStats();
    }
};

// Hide + LongShot + Track
class HideLongShotTrackBot : public HideBot, public LongShotBot, public TrackBot {
public:
    HideLongShotTrackBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + LongShot + Track" << endl;
        HideBot::displayStats();
        LongShotBot::displayStats();
        TrackBot::displayStats();
    }
};

// Hide + Track + ThirtyShot
class HideTrackThirtyShotBot : public virtual HideBot, public virtual TrackBot, public virtual ThirtyShotBot {
public:
    HideTrackThirtyShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + Track + ThirtyShot" << endl;
        HideBot::displayStats();
        TrackBot::displayStats();
        ThirtyShotBot::displayStats();
    }
};

// Hide + Track + SemiAuto
class HideTrackSemiAutoBot : public virtual HideBot, public virtual TrackBot, public virtual SemiAutoBot {
public:
    HideTrackSemiAutoBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + Track + SemiAuto" << endl;
        HideBot::displayStats();
        TrackBot::displayStats();
        SemiAutoBot::displayStats();
    }
};

// Hide + Track + LongShot
class HideTrackLongShotBot : public virtual HideBot, public virtual TrackBot, public virtual LongShotBot {
public:
    HideTrackLongShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + Track + LongShot" << endl;
        HideBot::displayStats();
        TrackBot::displayStats();
        LongShotBot::displayStats();
    }
};


// Hide + SemiAuto + Scout
class HideSemiAutoScoutBot : public virtual HideBot, public virtual SemiAutoBot, public virtual ScoutBot {
public:
    HideSemiAutoScoutBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + SemiAuto + Scout" << endl;
        HideBot::displayStats();
        SemiAutoBot::displayStats();
        ScoutBot::displayStats();
    }
};

// Hide + SemiAuto + Track
class HideSemiAutoTrackBot : public virtual HideBot, public virtual SemiAutoBot, public virtual TrackBot {
public:
    HideSemiAutoTrackBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + SemiAuto + Track" << endl;
        HideBot::displayStats();
        SemiAutoBot::displayStats();
        TrackBot::displayStats();
    }
};

// Hide + ThirtyShot + Scout
class HideThirtyShotScoutBot : public virtual HideBot, public virtual ThirtyShotBot, public virtual ScoutBot {
public:
    HideThirtyShotScoutBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + ThirtyShot + Scout" << endl;
        HideBot::displayStats();
        ThirtyShotBot::displayStats();
        ScoutBot::displayStats();
    }
};

// Hide + ThirtyShot + Track
class HideThirtyShotScoutBot : public virtual HideBot, public virtual ThirtyShotBot, public virtual TrackBot {
public:
    HideThirtyShotScoutBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + ThirtyShot + Scout" << endl;
        HideBot::displayStats();
        ThirtyShotBot::displayStats();
        TrackBot::displayStats();
    }
};

// Hide + Scout + ThirtyShot
class HideScoutThirtyShotBot : public virtual HideBot, public virtual ScoutBot, public virtual ThirtyShotBot {
public:
    HideScoutThirtyShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + Scout + ThirtyShot" << endl;
        HideBot::displayStats();
        ScoutBot::displayStats();
        ThirtyShotBot::displayStats();
    }
};

// Hide + Scout + SemiAuto
class HideScoutSemiAutoBot : public virtual HideBot, public virtual ScoutBot, public virtual SemiAutoBot {
public:
    HideScoutSemiAutoBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + Scout + SemiAuto" << endl;
        HideBot::displayStats();
        ScoutBot::displayStats();
        SemiAutoBot::displayStats();
    }
};

// Hide + Scout + LongShot
class HideScoutLongShotBot : public virtual HideBot, public virtual ScoutBot, public virtual LongShotBot {
public:
    HideScoutLongShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          HideBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield) {}

    void displayStats() const override {
        cout << "Upgrade: Hide + Scout + LongShot" << endl;
        HideBot::displayStats();
        ScoutBot::displayStats();
        LongShotBot::displayStats();
    }
};

#endif
