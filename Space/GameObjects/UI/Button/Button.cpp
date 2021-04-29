#include "Button.h"
#include <iostream>


bool Button::inner(const Point2D& p){
	bool f = true;
	f &= (position.x <= p.x && (position + scale).x >= p.x) || (position.x >= p.x && (position + scale).x <= p.x);
	f &= (position.y <= p.y &&  (position + scale).y >= p.y) || (position.y >= p.y && (position + scale).y <= p.y);

	return f; 
}

Button* Button::setAction(Action* action){
	this->action = action;
	return this;
}

Button* Button::setPosition(const Point2D& position) {
	this->position = position;
	return this;
}
Button* Button::setScale(const Vector2D& scale) {
	this->scale = scale;
	return this;
}
Button* Button::setAngle(const float angle) {
	this->angle = angle;
	return this;
}

Button* Button::setImage(const ImageType& img) {
	this->img = img;
	return this;
}



bool Button::activation(const Point2D& p){
	if(inner(p)) {
		action->run();
		return true;
	}
	return false;
}

void Button::draw() const {
	if(img != 0)
		Graphics::DrawObject::instance()->setPosition(position)
		->setScale(scale)
		->setAngle(angle)
		->setImage(img)
		->drawImage();
	else 
		Graphics::DrawObject::instance()->setPosition(position)
		->setScale(scale)
		->setAngle(angle)
		->setColor(sf::Color(150, 0, 0))
		->drawRectangle();

}

void Button::reaction() {
	if(action != nullptr) {
		if(EventController::instance()->onMouseLeftUp())
			activation(*(EventController::instance()->getMousePosition()));
	}
}