#include "BotController.h"
#include <iostream>

void BotController::calcNextStep(
		const GameScene& gc
	) {

	std::vecotr<std::vector<Vector2D > > pach(10);
	std::vector<size_t> scores;
	for(size_t epoch = 0; epoch < 10; ++epoch) {
		for(size_t id = 0; id < 10; ++id) {
			auto cp = gamecopy(gc);
		}
		

	}

}

Vector2D BotController::getDirection() {

	auto d = directions.back();
	directions.pop_back();
	return d;
}



Point2D BotController::getPoint() {


	return this->pos ;
}
