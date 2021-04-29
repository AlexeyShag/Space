#ifndef SPACE_SPACESHIP_H
#define SPACE_SPACESHIP_H


#include <Unit.h>
#include <Geometry.h>
#include <GameController.h>


class Bullet;
class SpaceShip : public Unit {
private:
    int numberOfResources = 0;
    int health = 500;
    Vector2D addtionalDirection;
    Point2D locationOfPortal;
    int capacity = 150;

    Vector2D moveD = Vector2D(0, 0);

    GameController* gameController = nullptr;

    //Point2D position;
    float mass = 10;
    float speed = 10;
    //float angle = 0;
    const float criticAngle = 2*Pi / 20;

    void rotate(float ang);
    void accelerate();
    void updatePositions();
    void friction(const float& len);

public:

    
    Bullet* shoot();
    void grabTheResource();
    void putTheResource();
    void fly();



    SpaceShip* setGameController(
        GameController* gc
    );

    virtual void move() override;
    //virtual void draw(const Vector2D& chunk) override;
};

class Bullet : public Unit {
public:
    int damage = 100;
};
#endif //SPACE_SPACESHIP_H
