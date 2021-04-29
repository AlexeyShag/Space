#include "Unit.h"
#include <iostream>

void Unit::move() {
	
}

void Unit::draw(const Vector2D& shift) {
	if(img != 0){

		Graphics::DrawObject::instance()->setPosition(position + shift)
		->setScale(scale)
		->setAngle(angle)
		->setImage(img)
		->drawImage();
	}else {
		//std::cout << this->angle << '\n';
		  Graphics::DrawObject::instance()->setPosition(position + shift)
        ->setScale(scale)
        ->setAngle(angle)
        ->setColor(sf::Color(150, 150, 0))
        ->drawRectangle();
    }
}

Unit* Unit::setPosition(const Point2D& pos) {

	this->position = pos;
	return this;
}

Unit* Unit::setScale(const Vector2D& scale) {
	this->scale = scale;
	return this;
}
Unit* Unit::setAngle(const float angle) {
	this->angle = angle;
	return this;
}

Unit* Unit::setSignColor(const Color& cl) {
	this->signColor = cl;
	return this;
}

const Color& Unit::getSignColor() {
	return this->signColor;
}

Unit* Unit::setSign(const bool f) {
	this->haveSign = f;
	return this;
}
            
bool Unit::isHaveSign() {
	return this->haveSign;
}

Unit* Unit::setImage(const ImageType& img) {
	//std::cout << img << '\n';
	this->img = img;
	return this;
}