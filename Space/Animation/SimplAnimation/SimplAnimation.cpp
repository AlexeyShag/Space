#include "SimplAnimation.h"

SimplAnimation* SimplAnimation::setAnimatObj(
		GameObject* obj 
	){

	animatObj = obj;
	return this;
}

SimplAnimation* SimplAnimation::setPositionAnimation(
		Poing2D* start,
		Poing2D* finish
	){

	startPosition = start;
	finishPosition = finish;
	return this;
}

SimplAnimation* SimplAnimation::setPositionAnimation(
		Vector2D* start,
		Vector2D* finish
	){
	startScale = start;
	finishScale = finish;
	return this;
}

SimplAnimation* SimplAnimation::setPositionAnimation(
		float* start,
		float* finish
	) {
	startAngle = start;
	finishAngle = finish;
	return this;
}

SimplAnimation& SimplAnimation::setTime(const size_t t) {
	time = t;
	now = 0;
	return this;
}

void SimplAnimation::restart() {
	now = 0;
	animatObj->setPosition(*startPosition);
	animatObj->setScale(*startScale);
	animatObj->setAngle(*startAngle);
}

bool SimplAnimation::next_step() {
	if(now < time){
		if(animatObj) {
			if(startPosition) {
				Poing2D* pos = animatObj->getPosition();
				pos = {
					pos.x + (finishPosition.x - startPosition.x) / time,
					pos.y + (finishPosition.y - startPosition.y) / time,
				};
				animatObj->setPosition(*pos);
			}
			if(startScale) {
				Vector2D* scale = animatObj->getScale();
				scale = {
					scale.x + (finishScale.x - startScale.x) / time,
					scale.y + (finishScale.y - startScale.y) / time,
				};
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