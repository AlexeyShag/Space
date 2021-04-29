#ifndef _COLOR_H_
#define _COLOR_H_

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Color {
private:
	unsigned char r = 0; // red
	unsigned char g = 0; // green
	unsigned char b = 0; // blue

	mutable sf::Color cl;

public:
	Color(unsigned char r, unsigned char g, unsigned char b);

	unsigned char& R();
	unsigned char& G();
	unsigned char& B();



	const sf::Color& getColor() const;


};


#endif




