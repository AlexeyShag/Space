#ifndef _CHUNK_H_
#define _CHUNK_H_

#include <vector>
#include <Unit.h>
#include <Geometry.h>

/*enum direction{
	up = 0,
	right = 1,
	down = 2,
	left = 3
};*/

class Chunk {
private:

	std::vector<Unit* > units;

	Point2D* leftTopCorne;
	Point2D* rightBottomCorner;

	Chunk* neighborChunk[4]; 
	// up - 0, right = 1, down = 2, left = 3
	
public:

	Chunk(
		Point2D* leftTop,
		Point2D* rightBottom
	);

	Chunk* add(
		Unit* obj
	);

	Chunk* addNeighborChunk(Chunk* chunk, size_t d);


	void next_step();

	void move();
	void rebuildSet(size_t maxSizeX, size_t maxSizeY);
	void draw(const Vector2D& shift);

	std::vector<Unit* >& getUnits();
	
	
};


#endif