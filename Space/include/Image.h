#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "SFML/Graphics.hpp"

class Image {
private:
	sf::Image img;
	sf::Sprite sp;
	sf::Texture t;
public:
	const sf::Image& getImage();
	const sf::Texture& getTexture();
	const sf::Sprite& getSprite();
	bool loadFromFile(const std::string& path);
	size_t getHieght();
	size_t getWidth();
};



#endif