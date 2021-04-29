#include "UI.h"

UI* UI::setPosition(const Point2D& position) {
	this->position = position;
	return this;
}
UI* UI::setScale(const Vector2D& scale) {
	this->scale = scale;
	return this;
}
UI* UI::setAngle(const float angle) {
	this->angle = angle;
	return this;
}
