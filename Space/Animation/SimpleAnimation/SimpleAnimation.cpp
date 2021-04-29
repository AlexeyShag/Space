#include "SimpleAnimation.h"

SimpleAnimation* SimpleAnimation::setAnimatObj(
		GameObject* obj 
	){

	animatObj = obj;
	return this;
}

SimpleAnimation* SimpleAnimation::setPositionAnimation(
		Point2D* start,
		Point2D* finish
	){

	startPosition = start;
	finishPosition = finish;
	return this;
}

SimpleAnimation* SimpleAnimation::setPositionAnimation(
		Vector2D* start,
		Vector2D* finish
	){
	startScale = start;
	finishScale = finish;
	return this;
}

SimpleAnimation* SimpleAnimation::setPositionAnimation(
		float* start,
		float* finish
	) {
	startAngle = start;
	finishAngle = finish;
	return this;
}

SimpleAnimation* SimpleAnimation::setTime(const size_t t) {
	time = t;
	now = 0;
	return this;
}

void SimpleAnimation::restart() {
	now = 0;
	animatObj->setPosition(*startPosition);
	animatObj->setScale(*startScale);
	animatObj->setAngle(*startAngle);
}

bool SimpleAnimation::next_step() {
	if(now < time){
		if(animatObj) {
			if(startPosition) {
				Point2D* pos = animatObj->getPosition();
				pos = new Point2D(
					pos->x + (finishPosition->x - startPosition->x) / time,
					pos->y + (finishPosition->y - startPosition->y) / time
				);
				animatObj->setPosition(*pos);
			}
			if(startScale) {
				Vector2D* scale = animatObj->getScale();
				scale = new Vector2D(
					scale->x + (finishScale->x - startScale->x) / time,
					scale->y + (finishScale->y - startScale->y) / time
				);
				animatObj->setScale(*scale);
			}
			if(startAngle) {
				float* angle = animatObj->getAngle();
				angle += (finishAngle - startAngle) / time;
				animatObj->setAngle(*angle);
			}
		}
		++now;
	}
	return now < time;

}