#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_

 #include <Geometry.h>


class GameController {
private:

protected:
    Vector2D direction = Vector2D(1, 0);
    
public:
    virtual Vector2D getDirection() = 0;
	virtual Point2D getPoint() = 0;
   
};



#endif