#include "EventController.h"

#include <iostream>


void EventController::refresh(sf::RenderWindow* win){
	sf::Event ev;
	
	auto pos = sf::Mouse::getPosition(*win);
	mousePosition = new Point2D(pos.x, pos.y);

	//isOnMouseLeftDown = false;
	isOnMouseLeftUp = false;
	//isOnMouseLeftPress = false;

	//isOnMouseRightDown = false;
	isOnMouseRightUp = false;
	//isOnMouseRightPress = false;
	

	closed = false;

	while(win->pollEvent(ev)) {
		switch (ev.type){
			case sf::Event::MouseButtonPressed: {
				if (ev.mouseButton.button ==
					sf::Mouse::Right) {
					if(!isOnMouseRightDown && !isOnMouseRightPress)
						isOnMouseRightDown = true;
					else 
						isOnMouseRightDown = false;
					isOnMouseRightPress = true;
				} else if (ev.mouseButton.button ==
					sf::Mouse::Left) {
					if(!isOnMouseLeftDown && !isOnMouseLeftPress)
						isOnMouseLeftDown = true;
					else 
						isOnMouseLeftDown = false;
					isOnMouseLeftPress = true;
				}
				break;
			}
			case sf::Event::MouseButtonReleased: {
				if (ev.mouseButton.button ==
					sf::Mouse::Right) {
					if(!isOnMouseRightUp && isOnMouseRightPress){
						isOnMouseRightUp = true;
						isOnMouseRightPress = false;
					}else 
						isOnMouseRightUp = false;
				} else if (ev.mouseButton.button ==
					sf::Mouse::Left) {
					if(!isOnMouseLeftUp && isOnMouseLeftPress){
						isOnMouseLeftUp = true;
						isOnMouseLeftPress = false;
					} else 
						isOnMouseLeftUp = false;
				}
				break;
			}
			case sf::Event::Closed: { 
				closed = true;
				break;
			}
			case sf::Event::KeyPressed: {
				if(ev.key.code == sf::Keyboard::W) keyCode[Key_::w] = true;
				if(ev.key.code == sf::Keyboard::D) keyCode[Key_::d] = true;
				if(ev.key.code == sf::Keyboard::S) keyCode[Key_::s] = true;
				if(ev.key.code == sf::Keyboard::A) keyCode[Key_::a] = true;
				if(ev.key.code == sf::Keyboard::Up) keyCode[Key_::up] = true;
				if(ev.key.code == sf::Keyboard::Left) keyCode[Key_::left] = true;
				if(ev.key.code == sf::Keyboard::Down) keyCode[Key_::down] = true;
				if(ev.key.code == sf::Keyboard::Right) keyCode[Key_::right] = true;
				break;
			}
			case sf::Event::KeyReleased: {
				if(ev.key.code == sf::Keyboard::W) keyCode[Key_::w] = false;
				if(ev.key.code == sf::Keyboard::D) keyCode[Key_::d] = false;
				if(ev.key.code == sf::Keyboard::S) keyCode[Key_::s] = false;
				if(ev.key.code == sf::Keyboard::A) keyCode[Key_::a] = false;
				if(ev.key.code == sf::Keyboard::Up) keyCode[Key_::up] = false;
				if(ev.key.code == sf::Keyboard::Left) keyCode[Key_::left] = false;
				if(ev.key.code == sf::Keyboard::Down) keyCode[Key_::down] = false;
				if(ev.key.code == sf::Keyboard::Right) keyCode[Key_::right] = false;
				break;
			}
			default:{

				break;
			}
		}		
	}
}

bool EventController::onMouseLeftDown() {
	return isOnMouseLeftDown;
}
bool EventController::onMouseLeftUp() {
	return isOnMouseLeftUp;
}
bool EventController::onMouseLeftPress(){
	return isOnMouseLeftPress;
}

bool EventController::onMouseRightDown() {
	return isOnMouseRightDown;
}
bool EventController::onMouseRightUp() {
	return isOnMouseRightUp;
}
bool EventController::onMouseRightPress() {
	return isOnMouseRightPress;
}

bool EventController::isClosed(){
	return closed;
}

Point2D* EventController::getMousePosition() {
	return mousePosition;
}

bool EventController::getKeyCode(size_t id) {
	return keyCode[id];
}
