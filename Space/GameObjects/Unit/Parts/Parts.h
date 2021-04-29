#ifndef SPACE_STAR_H
#define SPACE_STAR_H

#include <Unit.h>

class Parts : public Unit {
private:
	size_t timeLife;
 
public:
    
    Parts* setTimeLife(size_t l);
    virtual Parts* setImage(const ImageType& img);
    virtual Parts* setPosition(const Point2D& pos);
    virtual Parts* setScale(const Vector2D& scale);

    void explode();
};
#endif //SPACE_STAR_H
