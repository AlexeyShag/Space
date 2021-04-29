#ifndef _EventController_H_
#define _EventController_H_

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <Graphics.h>


#include <vector>


enum Key_{
    no = 0,
    w = 1,
    d = 2,
    s = 3,
    a = 4,
    up = 5,
    right = 6,
    down = 7,
    left = 8
};

class EventController {
private:   

	std::vector<sf::Event> buff;
	bool closed = false;

    // mouse events

    bool isOnMouseLeftDown = false;
    bool isOnMouseLeftUp = false;
    bool isOnMouseLeftPress = false;

    bool isOnMouseRightDown = false;
    bool isOnMouseRightUp = false;
    bool isOnMouseRightPress = false;

    //

    // keyboard

    bool keyCode[9] = {
        true
    };

    //



	Point2D* mousePosition = nullptr;


public:
	static EventController* instance(){
    	static EventController inst;
    	return &inst;
	}
 
    void refresh(sf::RenderWindow* win);
    size_t countEvents();

    bool isClosed();

    bool onMouseLeftDown();
    bool onMouseLeftUp();
    bool onMouseLeftPress();

    bool onMouseRightDown();
    bool onMouseRightUp();
    bool onMouseRightPress();

    bool getKeyCode(size_t id);



    Point2D* getMousePosition();


};




#endif