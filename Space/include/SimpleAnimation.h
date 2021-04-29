#ifndef _SIMPLANIMATION_H_
#define _SIMPLANIMATION_H_

#include <GameObject.h>

class SimpleAnimation {
private:

    Point2D* startPosition = nullptr;
    Point2D* finishPosition = nullptr;

    Vector2D* startScale = nullptr;
    Vector2D* finishScale = nullptr;

    float* startAngle = nullptr;
    float* finishAngle = nullptr;

    GameObject* animatObj = nullptr;

    size_t time = 0;
    size_t now = 0;


public:

	SimpleAnimation* setAnimatObj(
		GameObject* obj 
	);

	SimpleAnimation* setPositionAnimation(
		Point2D* start,
		Point2D* finish
	);

	SimpleAnimation* setPositionAnimation(
		Vector2D* start,
		Vector2D* finish
	);

	SimpleAnimation* setPositionAnimation(
		float* start,
		float* finish
	);
    
    SimpleAnimation* setTime(const size_t t);

    void restart();
    bool next_step();

};

#endif

