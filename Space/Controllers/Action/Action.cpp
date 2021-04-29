#include "Action.h"

Action::Action(const std::function<void()>& a){
	this->action = a;
}
void Action::run(){
	this->action();
}