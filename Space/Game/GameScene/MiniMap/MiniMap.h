#ifndef _MINIMAP_H_
#define _MINIMAP_H_

#include <Graphics.h>
#include <Chunk.h>



class MiniMap {
private:

	enum Map {
		mini = 0,
		big = 1,
		large = 2

	} now = Map::big;
	Point2D positions[3] = {
		Point2D(0, 0),
		Point2D(600, 400),
		Point2D(650, 450)
	};
	Vector2D scale[3] = {
		Vector2D(800, 600),
		Vector2D(200, 200),
		Vector2D(150, 150)
	};

	Vector2D worldSize;

	

public:
	MiniMap(const Vector2D& sz);
	void clear();
	void draw(Chunk* chunk);
	
};


#endif