#ifndef SPACE_STAR_H
#define SPACE_STAR_H
#include "../Unit/unit.h"
class Star : public unit {
private:
    int timer;
public:
    Star() {
        timer = 120;
    }

    void explode();
};
#endif //SPACE_STAR_H
