#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include <Chunk.h>
#include <Scene.h>
#include <MiniMap.h>
#include <vector>

#include <EventController.h>
#include <Geometry.h>

#include <PlayerController.h>

#include <Unit.h>
#include <Graphics.h>

class GameScene: public Scene {
private:

	static const size_t cntXChunk = 3;
	static const size_t cntYChunk = 3;
	static const size_t xChunkSize = 1000;
	static const size_t yChunkSize = 1000;
	Chunk* gameArea[cntXChunk][cntYChunk];
	MiniMap* miniMap = nullptr;

	Vector2D shift = Vector2D(0, 0);

	Unit* target;

public:

	static size_t getWorldHieght();
	static size_t getWorldWidht();

	GameScene();
	virtual void draw();
	virtual GameScene* addUnit(Unit* unit);
	GameScene* addTarget(Unit* unit);
};



#endif