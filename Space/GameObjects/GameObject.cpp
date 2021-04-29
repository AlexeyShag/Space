#include "GameObject.h"

GameObject* GameObject::setPosition(const Point2D& position) {
	this->position = position;
	return this;
}
GameObject* GameObject::setScale(const Vector2D& scale) {
	this->scale = scale;
	return this;
}
GameObject* GameObject::setAngle(const float angle) {
	this->angle = angle;
	return this;
}


Point2D* GameObject::getPosition() {
	return &position; 
}
Vector2D* GameObject::getScale() {
	return &scale;
}
float* GameObject::getAngle() {
	return &angle;
}