#include "MiniMap.h"
#include <iostream>

MiniMap::MiniMap(const Vector2D& sz) {
	worldSize = sz;
}

void MiniMap::clear() {

	Graphics::DrawObject::instance()->setPosition(positions[now])
	->setScale(scale[now])
	->setColor(sf::Color(50, 50, 50))
	->drawRectangle();
}

void MiniMap::draw(Chunk* chunk) {
	for(auto u: chunk->getUnits()){
		if(u->isHaveSign()){
			Point2D pos = Point2D(
				u->getPosition()->x / worldSize.x * scale[now].x + positions[now].x,
				u->getPosition()->y / worldSize.y * scale[now].y + positions[now].y
			);
			Graphics::DrawObject::instance()->setPosition(pos)
			->setScale(Vector2D(5, 5))
			->setColor(u->getSignColor().getColor())
			->drawRectangle();
		}
	}

}	
