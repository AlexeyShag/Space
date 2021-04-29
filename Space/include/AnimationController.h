#ifndef _ANIMATIONCONTROLLER_H_
#define _ANIMATIONCONTROLLER_H_

#include <ComplexAnimation.h>
#include <vector>

class AnimationController {
private:
    std::vector<ComplexAnimation* > complexAnimations;
public:

    AnimationController* add(
        ComplexAnimation* anim
        );
    bool next_step();
    
};

#endif