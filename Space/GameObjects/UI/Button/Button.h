#ifndef _BUTTON_H_
#define _BUTTON_H_


#include <UI.h>



class Button: public UI {
private:
	Action* action = nullptr;
	bool inner(const Point2D& p);
	ImageType img = ImageType::nothing;
 
public:	
	bool activation(const Point2D& p);

	virtual void draw() const override;
	virtual void reaction() override;

	Button* setAction(Action* a);
	virtual Button* setPosition(const Point2D& position);
    virtual Button* setScale(const Vector2D& scale);
    virtual Button* setAngle(const float angle);

    virtual Button* setImage(const ImageType& img);
};




#endif