#include "SpaceShip.h"
#include <iostream>

void normaliseAngle(float& a){
    while(a > 2 * Pi)
        a -= 2 * Pi;
    while(a < 0) {
        a += 2 * Pi;
    }
}


SpaceShip* SpaceShip::setGameController(GameController* gm) {
    this->gameController = gm;
    return this;
}

void SpaceShip::rotate(float ang) {
    normaliseAngle(ang);
    float d1 = ang - this->angle;
    float d2 = this->angle - ang;

    normaliseAngle(d1);
    normaliseAngle(d2);

    if(d1 < d2){
        this->angle += std::min(d1, criticAngle);
    } else {
        this->angle -= std::min(d2, criticAngle);
    }
    normaliseAngle(this->angle);
}

void SpaceShip::accelerate(){
    speed = 2;
    Vector2D d(this->angle);
    moveD += speed * d;
}

void SpaceShip::updatePositions(){
    position += moveD;
}

void SpaceShip::friction(const float& len) {
    if(len < 25){
        moveD *= sqrtf(len / 100.) * 0.85;
    } else if(len < 10){
        moveD *= 0;
    }
    moveD *= 0.85;
}


void SpaceShip::move() {
    if(gameController == nullptr)
        return;
    Vector2D d = gameController->getDirection();
    //std::cout << d.getLen() << '\n';
    rotate(d.getAngle());
    accelerate();
    updatePositions();
    friction(d.getLen());
   // std::cout << this->angle << '\n';

}

/*

void SpaceShip::draw() {
    Graphics::DrawObject::instance()->setPosition(position)
        ->setScale(scale)
        ->setAngle(angle)
        ->setColor(sf::Color(150, 150, 0))
        ->drawRectangle();
}*/