#ifndef _UI_H_
#define _UI_H_

#include <GameObject.h>


class UI : public GameObject {
protected:
public:
    virtual void draw() const  = 0;
    virtual void reaction() = 0;

    virtual UI* setPosition(const Point2D& position);
    virtual UI* setScale(const Vector2D& scale);
    virtual UI* setAngle(const float angle);

};

#endif

