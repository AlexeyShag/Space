#include "Color.h"




Color::Color(
		unsigned char r,
		unsigned char g,
		unsigned char b
	): r(r), g(g), b(b){}

unsigned char& Color::R() {
	return r;
}

unsigned char& Color::G() {
	return g;
}

unsigned char& Color::B() {
	return b;
}



const sf::Color& Color::getColor() const{
	cl.r = r;
	cl.g = g;
	cl.b = b;
	return cl;
}




