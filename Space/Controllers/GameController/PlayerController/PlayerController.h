#ifndef _PLAYERCONTROLLER_H_
#define _PLAYERCONTROLLER_H_


#include <GameController.h>
#include <EventController.h>

class PlayerController: public GameController {
private:

	Point2D pos = Point2D(400, 300);
    
public:

	static PlayerController* instance(){
    	static PlayerController inst;
    	return &inst;
	}
	
    virtual Vector2D getDirection();
    virtual Point2D getPoint();
};



#endif