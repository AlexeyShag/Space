#ifndef _SCENE_H_
#define _SCENE_H_

#include <UI.h>
#include <vector>

class Scene {
protected:
	std::vector<UI* > items;

public:

	Scene* add(UI* item);

	virtual void draw();
	void listenEvent();

};


#endif