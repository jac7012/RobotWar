#ifndef NEWROBOT_H
#define NEWROBOT_H

#include <string>

using namespace std;

struct Position {
    int robotPositionX;
    int robotPositionY;
};

class Robot {
protected:
    string name;
    Position pos;
    int health;
    int shells;
    int lives;
    bool alive;
    int fieldWidth;
    int fieldHeight;

public:
    Robot(string n, int x, int y, int w, int h)
        : name(n), fieldWidth(w), fieldHeight(h) {
        pos.robotPositionX = x;
        pos.robotPositionY = y;
        health = 100;
        shells = 10;
        lives = 3;
        alive = true;
    }

    virtual ~Robot() {}

    virtual void think() = 0;
    virtual void look() = 0;
    virtual void move() = 0;
    virtual void fire() = 0;
    virtual void displayAction() = 0;

    string getName() const {
        return name;
    }

    Position getPosition() const {
        return pos;
    }

    bool isLives() const {
        return alive;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            lives--;
            if (lives <= 0) {
                alive = false;
            }
        }
    }
};

#endif // NEWROBOT_H
