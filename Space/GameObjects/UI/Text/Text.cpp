#include "Text.h"
#include <iostream>


void Text::draw() const {
	Graphics::DrawObject::instance()
	->setPosition(position)
	->setScale(scale)
	->setAngle(angle)
	->setString(text)
	->drawText();
}

Text* Text::setString(const std::string& s){
	this->text = s;
	return this;
}


void Text::reaction() {
}