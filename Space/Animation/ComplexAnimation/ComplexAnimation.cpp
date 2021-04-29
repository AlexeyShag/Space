#include "ComplexAnimation.h"


ComplexAnimation* ComplexAnimation::addSimpleAnimation(
		SimpleAnimation* anim
		){
	simpleAnimations.push_back(anim);
	return this;
}

void ComplexAnimation::setRepet(bool f) {
	reapeat = f;
}
bool ComplexAnimation::isRepeat() {
	return reapeat;
}
void ComplexAnimation::restart() {
	now = 0;
}

bool ComplexAnimation::next_step() {
	if(now < simpleAnimations.size()) {
		if(!simpleAnimations[now]->next_step()) {
			++now;

			if(reapeat && now == simpleAnimations.size())
				now = 0;

			if(now != simpleAnimations.size())
				simpleAnimations[now]->restart();
		}
	}
	return now < simpleAnimations.size();
}
