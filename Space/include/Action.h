#ifndef _ACTION_H_
#define _ACTION_H_


#include<functional>

class Action {
private:
	std::function<void()> action;
public:
	
	Action(const std::function<void()>& a);
	void run();
};

#endif