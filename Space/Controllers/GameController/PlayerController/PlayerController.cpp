#include "PlayerController.h"
#include <iostream>

Vector2D PlayerController::getDirection() {
	this->direction.norm();
	if(EventController::instance()->getKeyCode(Key_::up) ||
	   EventController::instance()->getKeyCode(Key_::w)) {
		//this->direction *= 100;

	   	//return this->direction;
		//this->direction += d;
	}	

	if(EventController::instance()->getKeyCode(Key_::down) ||
	   EventController::instance()->getKeyCode(Key_::s)) {
	   	//this->direction *= 5;
		//this->direction -= d;
	}	

	if(EventController::instance()->getKeyCode(Key_::right) ||
	   EventController::instance()->getKeyCode(Key_::d)) {
		this->direction.rotate(Pi / 40);

	}	

	if(EventController::instance()->getKeyCode(Key_::left) ||
	   EventController::instance()->getKeyCode(Key_::a)) {
		this->direction.rotate(-(Pi / 40));

	}	

	//this->direction *= 100;

	return this->direction * 70 ;
}



Point2D PlayerController::getPoint() {
	this->direction.norm();
	if(EventController::instance()->getKeyCode(Key_::up) ||
	   EventController::instance()->getKeyCode(Key_::w)) {
		//this->direction *= 100;
		this->pos.y -= 5;
		
	   	//return this->direction;
		//this->direction += d;
	}	

	if(EventController::instance()->getKeyCode(Key_::down) ||
	   EventController::instance()->getKeyCode(Key_::s)) {
	    this->pos.x -= 5;
	   	//this->direction *= 5;
		//this->direction -= d;
	}	

	if(EventController::instance()->getKeyCode(Key_::right) ||
	   EventController::instance()->getKeyCode(Key_::d)) {
		this->pos.x += 5;

	}	

	if(EventController::instance()->getKeyCode(Key_::left) ||
	   EventController::instance()->getKeyCode(Key_::a)) {
		this->pos.x -= 5;

	}	

	return this->pos ;
}
