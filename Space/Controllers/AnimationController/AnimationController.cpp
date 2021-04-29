#include "AnimationController.h"

AnimationController* AnimationController::add(
	ComplexAnimation* anim
	) {
	complexAnimations.push_back(anim);
	return this;
}
	
bool AnimationController::next_step() {

	for(size_t i = 0; i < complexAnimations.size(); ++i) {
		if(!complexAnimations[i]->next_step()) {
			std::swap(complexAnimations[i], complexAnimations.back());
			complexAnimations.pop_back();
			--i;
		}
	}

	return complexAnimations.size() != 0;
}