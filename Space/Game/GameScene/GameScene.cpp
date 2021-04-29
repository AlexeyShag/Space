
#include "GameScene.h"
#include <iostream>

int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0, 1, 0, -1};

GameScene::GameScene() {
	for(size_t x = 0; x < cntXChunk; ++x) {
		for(size_t y = 0; y < cntYChunk; ++y) {
			gameArea[x][y] = new Chunk(
				new Point2D(x * xChunkSize, y * yChunkSize),
				new Point2D((x + 1) * xChunkSize - 1, (y +1) * yChunkSize - 1)
			);
		}
	}
	for(size_t x = 0; x < cntXChunk; ++x) {
		for(size_t y = 0; y < cntYChunk; ++y) {
			for(size_t i = 0; i < 4; ++i) {
				gameArea[x][y]->addNeighborChunk(gameArea[(x + dx[i]+ cntXChunk) % cntXChunk][(y + dy[i] + cntYChunk) % cntYChunk], i);
			}
		}	
	}
	miniMap = new MiniMap(
		Vector2D(xChunkSize * cntXChunk, 
				 yChunkSize * cntYChunk)
	);
}

size_t GameScene::getWorldHieght() {
	return yChunkSize * cntYChunk;
}

size_t GameScene::getWorldWidht() {
	return xChunkSize * cntXChunk;
}

void GameScene::draw() {

	if(this->target == nullptr) {

	}

	for(size_t x = 0; x < cntXChunk; ++x) {
		for(size_t y = 0; y < cntYChunk; ++y) {
			gameArea[x][y]->move();
			gameArea[x][y]->rebuildSet(
				xChunkSize * cntXChunk,
				yChunkSize * cntYChunk
				);
		}
	}
	auto pos = target->getPosition();
	auto winSize = Graphics::instance()->getWinSize();

	shift = Vector2D{
		-(pos->x - winSize.x / 2),
		-(pos->y - winSize.y / 2)
	};
	//std::cout << '[' <<'\n';
	bool d[4] = {false, false, false, false};
	for(int x = -1; x < int(cntXChunk) + 1; ++x) {
		for(int y = -1; y < int(cntYChunk) + 1; ++y) {
			if(x == -1) {
				x += cntXChunk;
				d[0] = true;
				shift -= Vector2D(cntXChunk * xChunkSize, 0);
			}
			if(y == -1) {
				y += cntYChunk;
				d[1] = true;
				shift -= Vector2D(0, cntYChunk * yChunkSize);
			}
			if(x == cntXChunk) {
				x -= cntXChunk;
				d[2] = true;
				shift += Vector2D(cntXChunk * xChunkSize, 0);
			}
			if(y == cntYChunk) {
				y -= cntYChunk;
				d[3] = true;
				shift += Vector2D(0, cntYChunk * yChunkSize);
			}
			//std::cout << shift.x <<' ' << shift.y << '\n';
			gameArea[x][y]->draw(shift);

			if(d[0]) {
				x -= cntXChunk;
				d[0] = false;
				shift += Vector2D(cntXChunk * xChunkSize, 0);
			}
			if(d[1]) {
				y -= cntYChunk;
				d[1] = false;
				shift += Vector2D(0, cntYChunk * yChunkSize);
			}
			if(d[2]) {
				x += cntXChunk;
				d[2] = false;
				shift -= Vector2D(cntXChunk * xChunkSize, 0);
			}
			if(d[3]) {
				y += cntYChunk;
				d[3] = false;
				shift -= Vector2D(0, cntYChunk * yChunkSize);
			}

		}
	}

	//std::cout << ']' <<'\n';

	for(UI* item : items) {
		item->draw();
	}


	miniMap->clear();
	for(size_t x = 0; x < cntXChunk; ++x) {
		for(size_t y = 0; y < cntYChunk; ++y) {
			miniMap->draw(gameArea[x][y]);
		}
	}


}

GameScene* GameScene::addUnit(Unit* unit) {


	size_t x = unit->getPosition()->x;
	size_t y = unit->getPosition()->y;
	x = x / xChunkSize;
	y = y / yChunkSize;
	//std::cout << x << ' ' << y << '\n';
	gameArea[x][y]->add(unit);

	return this;
}

GameScene* GameScene::addTarget(Unit* unit) {

	this->target = unit;
	addUnit(unit);
	return this;
}


