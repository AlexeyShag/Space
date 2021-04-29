#ifndef _GAME_H_
#define _GAME_H_

#include <Graphics.h>
#include <Scene.h>
#include <GameScene.h>
// UI
#include <Button.h>
#include <Text.h>
#include <UIBox.h>
//

// Unit
#include <Parts.h>
#include <SpaceShip.h>
//

#include <EventController.h>
#include <ActionController.h>
#include <Action.h>

class Game {
private:
	bool run = false;
	void next_step();
	void init(size_t width, size_t height);

	enum scene {
		MainMenu,
		MainSettings, 
		GameSpace
	};

	scene presentScene = scene::MainMenu;

	static void openGameSpace(){
		Game::instance()->presentScene = Game::scene::GameSpace;
	}

	static void openMainSettings(){
		Game::instance()->presentScene = Game::scene::MainSettings;
	}

	static void openMainMenu(){
		Game::instance()->presentScene = Game::scene::MainMenu;
	}

	static void stopGame(){
		Game::instance()->run = false;
	}

	Scene* mainMenu = nullptr;
	Scene* gameSpace = nullptr;
	Scene* mainSettings = nullptr;
public:
	//Game() = delete;
	static Game* instance(){
    	static Game inst;
    	return &inst;
	}
	int Execute(size_t width, size_t height);
	void render();

	void Exit();
};

#endif