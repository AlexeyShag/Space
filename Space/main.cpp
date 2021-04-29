#include <iostream>
#include <Game.h>

int main(){
	Game::instance()->Execute(800, 600);
	return 0;
}