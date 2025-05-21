#ifndef ROBOT_H
#define ROBOT_H

#include <string>
using namespace std;

class Robot {
protected:
    string name;
    int x, y;
    int lives;
    int shells;
    bool isAlive;

public:
    Robot(string n, int xPos, int yPos)
        : name(n), x(xPos), y(yPos), lives(3), shells(10), isAlive(true) {}

    virtual void think() = 0;
    virtual void look() = 0;
    virtual void move() = 0;
    virtual void fire() = 0;
    virtual void displayAction() = 0;

    bool alive() const { return isAlive; }
    string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }

    void destroy() {
        isAlive = false;
    }

    virtual ~Robot() {}
};

#endif
