#ifndef _SIMPLANIMATION_H_
#define _SIMPLANIMATION_H_


class SimplAnimation {
private:

    Point2D* startPosition = nullptr;
    Poing2D* finishPosition = nullptr;

    Vector2D* startScale = nullptr;
    Vector2D* finishScale = nullptr;

    float* startAngle = nullptr;
    float* finishAngle = nullptr;

    GameObject* animatObj = nullptr;

    size_t time = 0;
    size_t now = 0;


public:

	SimplAnimation* setAnimatObj(
		GameObject* obj 
	);

	SimplAnimation* setPositionAnimation(
		Poing2D* start,
		Poing2D* finish
	);

	SimplAnimation* setPositionAnimation(
		Vector2D* start,
		Vector2D* finish
	);

	SimplAnimation* setPositionAnimation(
		float* start,
		float* finish
	);
    
    SimplAnimation& setTime(const size_t t);

    void restart();
    bool next_step();

};

#endif

