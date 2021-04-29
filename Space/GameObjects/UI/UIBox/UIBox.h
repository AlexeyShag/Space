#ifndef _UIBOX_H_
#define _UIBOX_H_


#include <UI.h>
#include <vector>


class UIBox: public UI {
private:
	std::vector<UI* > items;
public:	
	UIBox* addItem(
		UI* item
		);
	virtual void draw() const override;
	virtual void reaction() override;

	virtual UIBox* setPosition(const Point2D& position);
    virtual UIBox* setScale(const Vector2D& scale);
    virtual UIBox* setAngle(const float angle);
};




#endif