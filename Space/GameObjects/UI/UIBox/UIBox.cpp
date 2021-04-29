#include "UIBox.h"

UIBox* UIBox::addItem(
	UI* item 
	){
	items.push_back(item);
	return this;
}

void UIBox::draw() const{
	Graphics::DrawObject::instance()->setPosition(position)
	->setScale(scale)
	->setAngle(angle)
	->setColor(sf::Color(0, 150, 0))
	->drawRectangle();

	for(UI* item: items) {
		item->draw();
	}
}

UIBox* UIBox::setPosition(const Point2D& position) {
	this->position = position;
	return this;
}
UIBox* UIBox::setScale(const Vector2D& scale) {
	this->scale = scale;
	return this;
}
UIBox* UIBox::setAngle(const float angle) {
	this->angle = angle;
	return this;
}

void UIBox::reaction() {
	for(UI* item: items) {
		item->reaction();
	}
}