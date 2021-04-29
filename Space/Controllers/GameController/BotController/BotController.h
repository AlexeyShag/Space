#ifndef _BOTCONTROLLER_H_
#define _BOTCONTROLLER_H_


#include <GameController.h>
#include <GameScene.h>



class BotController: public GameController {
private:

	Point2D pos = Point2D(400, 300);
	std::vector<Vector2D > directions;
	size_t cntBots = 0;

	void calcNextStep(const GameScene& gc);
    
public:

	static BotController* instance(){
    	static BotController inst;
    	return &inst;
	}
	
    virtual Vector2D getDirection();
    virtual Point2D getPoint();
};



#endif