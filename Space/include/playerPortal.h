#ifndef SPACE_PLAYERPORTAL_H
#define SPACE_PLAYERPORTAL_H
#include "../Unit/unit.h"
#include "../Spaceship/spaceship.h"

class PlayerPortal : public Unit {
    int resource;
    Spaceship* owner;

};

#endif //SPACE_PLAYERPORTAL_H
