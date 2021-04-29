#include "Graphics.h"
#include <iostream>

void Graphics::createWindow(unsigned int w, unsigned int h){

    width = w;
    height = h;
    win = new sf::RenderWindow(sf::VideoMode(width, height), "Space");
}

Vector2D Graphics::getWinSize() {
    return Vector2D(width, height);
}

void Graphics::render(){
    win->display();
    win->clear();
}

sf::RenderWindow* Graphics::getWindow(){
    return win;
}

/////////////////////////////////Rect//////////////////

Graphics::DrawObject* Graphics::DrawObject::setPosition(const Point2D& pos){
    this->position = pos;
    return this;
}

Graphics::DrawObject* Graphics::DrawObject::setAngle(const float angle){
    this->angle = angle;
    return this;
}
Graphics::DrawObject* Graphics::DrawObject::setScale(const Vector2D& sc){
    this->scale = sc;
    return this;
}   

Graphics::DrawObject* Graphics::DrawObject::setColor(const sf::Color& col){
    this->color = col;
    return this;
}

Graphics::DrawObject* Graphics::DrawObject::setString(const std::string& s){
    this->s = s;
    return this;
}   

Graphics::DrawObject* Graphics::DrawObject::setImage(const ImageType& img){
    this->img = img;
    return this;
}

Graphics::DrawObject* Graphics::DrawObject::setFont(const sf::Font& font){
    this->font = font;
    return this;
}

Graphics::DrawObject* Graphics::DrawObject::setSize(const float& sz){
    this->size = sz;
    return this;
}

void Graphics::DrawObject::drawRectangle(){
    shape.setFillColor(color);
    shape.setPosition(sf::Vector2f(position.x, position.y));
    shape.setSize(sf::Vector2f(scale.x, scale.y));
    transform.rotate(
        angle * 180 / Pi,
        sf::Vector2f(
            (position.x + (position + scale).x) / 2,
            (position.y + (position + scale).y) / 2
        )
    );
    Graphics::instance()->getWindow()->draw(shape, transform);
    transform.rotate(
        -angle * 180 / Pi,
        sf::Vector2f(
            (position.x + (position + scale).x) / 2,
            (position.y + (position + scale).y) / 2
        )
    );
}   

void Graphics::DrawObject::drawText(){
    text.setFillColor(color);
    text.setPosition(sf::Vector2f(position.x, position.y));
    text.setString(s);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color(0,0,150));
    transform.rotate(
        angle * 180 / Pi,
        sf::Vector2f(
            (position.x + (position + scale).x) / 2,
            (position.y + (position + scale).y) / 2
        )
    );
    Graphics::instance()->getWindow()->draw(text);
    transform.rotate(
        -angle * 180 / Pi,
        sf::Vector2f(
            (position.x + (position + scale).x) / 2,
            (position.y + (position + scale).y) / 2
        )
    );
}   

void Graphics::DrawObject::drawImage(){
    sf::Sprite sp;
    sp.setPosition(sf::Vector2f(position.x, position.y));
    
    sp.setTexture(
        ImageController::instance()->buttonImg[img]->getTexture()
        );
    transform.rotate(
        angle * 180 / Pi,
        sf::Vector2f(
            (position.x + (position + scale).x) / 2,
            (position.y + (position + scale).y) / 2
        )
    );
    transform.scale(
            1. * scale.x / ImageController::instance()->buttonImg[img]->getHieght(),
            1. * scale.y / ImageController::instance()->buttonImg[img]->getWidth(),
            (position.x),
            (position.y)
    );
    Graphics::instance()->getWindow()->draw(sp, transform);

    transform = sf::Transform();
}   

sf::Image Graphics::Image::getImage(){
    return img;
}
bool Graphics::Image::loadFromFile(const std::string& path){
    return img.loadFromFile(path);
}

sf::Font Graphics::Font::getFont(){
    return font;
}
void Graphics::Font::loadFromFile(const std::string& path){
    font.loadFromFile(path);
}
