#ifndef _TEXT_H_
#define _TEXT_H_


#include <UI.h>
#include <string>


class Text: public UI {
private:
	std::string text = "";

public:	
	virtual void draw() const override;
	virtual void reaction() override;
	Text* setString(const std::string& s);
};




#endif