#include "Parts.h"
#include <iostream>

Parts* Parts::setTimeLife(size_t l = 100) {

	timeLife = l;
    return this;
}

Parts* Parts::setImage(const ImageType& img) {
	//std::cout << img << '\n';
	this->img = img;
	return this;
}

Parts* Parts::setPosition(const Point2D& pos) {
	this->position = pos;
	return this;
}

Parts* Parts::setScale(const Vector2D& scale) {
	this->scale = scale;
	return this;
}
