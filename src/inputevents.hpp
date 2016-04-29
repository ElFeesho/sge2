#ifndef __INPUTEVENTS_HPP__
#define __INPUTEVENTS_HPP__

#include "inputadapter.hpp"
#include <functional>

using std::function;

class InputEvents
{
public:
    InputEvents(InputAdapter *inputAdapter);

	void processEvents(function<void()> quitEvent);

	int mouseX();
	int mouseY();

	int mouseButton();
private:
    InputAdapter *input;
};

#endif
