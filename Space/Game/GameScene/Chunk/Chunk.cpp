#include "Chunk.h"
#include <iostream>


Chunk::Chunk(
	Point2D* leftTop,
	Point2D* rightBottom
	) {
	leftTopCorne = leftTop;
	rightBottomCorner = rightBottom;
}
Chunk* Chunk::add(
	Unit* obj
	) {
	units.push_back(obj);
	return this;
}
void Chunk::next_step() {
	for(auto obj : units){
		obj->move();
	}
}

Chunk* Chunk::addNeighborChunk(Chunk* chunk, size_t d) {
	neighborChunk[d] = chunk;
	return this;
}

void Chunk::move() {
	for(Unit* unit : units) {
		unit->move();
	}
}

void normPos(
	Unit*& u, size_t maxSizeX = 100, size_t maxSizeY = 100
	) {

	auto p = u->getPosition();
	if(p->x < 0) {
		p->x += maxSizeX;
	}
	if(p->y < 0) {
		p->y += maxSizeY;
	}
	if(p->x > maxSizeX) {
		p->x -= maxSizeX;
	}
	if(p->y > maxSizeY) {
		p->y -= maxSizeY;
	}
	u->setPosition(*p);
}


void Chunk::rebuildSet(
	size_t maxSizeX = 100, size_t maxSizeY = 100
	) {
	
	for(int i = 0; i < units.size(); ++i) {
		normPos(units[i], maxSizeX, maxSizeY);
		// up
		if(units[i]->getPosition()->x < leftTopCorne->x) {
			neighborChunk[0]->units.push_back(units[i]);
			std::swap(units[i], units[units.size() - 1]);
			units.pop_back();
			--i;
		} else 
		// left
		if(units[i]->getPosition()->y < leftTopCorne->y) {
			neighborChunk[3]->units.push_back(units[i]);
			std::swap(units[i], units[units.size() - 1]);
			units.pop_back();
			--i;
		} else 
		// down
		if(units[i]->getPosition()->x > rightBottomCorner->x) {
			neighborChunk[1]->units.push_back(units[i]);
			std::swap(units[i], units[units.size() - 1]);
			units.pop_back();
			--i;
		} else
		// right
		if(units[i]->getPosition()->y > rightBottomCorner->y) {
			neighborChunk[2]->units.push_back(units[i]);
			std::swap(units[i], units[units.size() - 1]);
			units.pop_back();
			--i;
		}
	}
}

void Chunk::draw(const Vector2D& shift = Vector2D(0, 0)) {
	for(Unit* unit : units) {
		unit->draw(shift);
	}
}

std::vector<Unit*>& Chunk::getUnits() {
	return units;
}