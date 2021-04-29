#include "Image.h"


const sf::Image& Image::getImage(){
	return img;
}

const sf::Texture& Image::getTexture(){
	return t;
}

const sf::Sprite& Image::getSprite(){
	return sp;
}

bool Image::loadFromFile(const std::string& path){
	bool f = img.loadFromFile(path);

    t.loadFromImage(
        img
    );

    sp.setTexture(t);

    return f;
}

size_t Image::getHieght() {
	return img.getSize().x;
}
size_t Image::getWidth(){
	return img.getSize().y;
}

