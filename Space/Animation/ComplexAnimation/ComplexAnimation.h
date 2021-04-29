#ifndef _COMPLEXANIMATION_H_
#define _COMPLEXANIMATION_H_

#include <vector>
#include <SimpleAnimation.h>
//#include "../../Geometry/Geometry.h"

class ComplexAnimation {
private:

	std::vector<SimpleAnimation* > simpleAnimations;
	bool reapeat = false;
	size_t now = 0;

public:

	ComplexAnimation* addSimpleAnimation(
		SimpleAnimation* anim
		);
	void setRepet(bool f);
	bool isRepeat();
	
	void restart();
	bool next_step();

};

#endif

