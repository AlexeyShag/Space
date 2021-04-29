//
// Created by Анастасия on 18.03.2021.
//

#ifndef SPACE_UNIT_H
#define SPACE_UNIT_H

#include <Geometry.h>
#include <GameObject.h>
#include <Color.h>

class Unit: public GameObject {
protected:
    int speedOfMovement;
    Point2D location;
    Vector2D mainDirection;
    //float angle;
    int mass;
    ImageType img = ImageType::nothing;

    Color signColor = Color(150, 150, 0);

    bool haveSign = true;

public:


    virtual void move();
    virtual void draw(const Vector2D& shift);

    virtual Unit* setPosition(const Point2D& pos) override;
    virtual Unit* setScale(const Vector2D& scale) override; 
    virtual Unit* setAngle(const float angle) override;
    virtual Unit* setSignColor(const Color& cl);
    virtual Unit* setSign(const bool f);
    virtual Unit* setImage(const ImageType& img);
            
    virtual bool isHaveSign();

    virtual const Color& getSignColor();

};
#endif //SPACE_UNIT_H
