#ifndef SPACE_PLANET_H
#define SPACE_PLANET_H
#include "../Unit/unit.h"
#include "../Asteroid/asteroid.h"

class Planet : public Asteroid {
public:
    int resource;
};
#endif //SPACE_PLANET_H
