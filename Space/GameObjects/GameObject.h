#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <EventController.h>
#include <ImageController.h>
#include <Action.h>


class GameObject {
protected:
    Point2D position;
    Vector2D scale;
    float angle = 0;

public:
    virtual GameObject* setPosition(const Point2D& position);
    virtual GameObject* setScale(const Vector2D& scale);
    virtual GameObject* setAngle(const float angle);

    virtual Point2D* getPosition();
    Vector2D* getScale();
    float* getAngle();
};

#endif

