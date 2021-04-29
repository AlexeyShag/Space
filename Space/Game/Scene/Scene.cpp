#include "Scene.h"
#include <iostream>

Scene* Scene::add(UI* item){
	this->items.push_back(item);
	return this;
}

void Scene::draw() {
	//std::cerr << "Button have Drawen" << '\n';
	for(UI* item : items) {
		item->draw();
	}
}

void Scene::listenEvent() {
	for(UI* item : items) {
		item->reaction();
	}
}