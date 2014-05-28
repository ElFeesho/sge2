#ifndef __INPUTEVENTS_HPP__
#define __INPUTEVENTS_HPP__

#include <functional>

using std::function;

class InputEvents
{
public:
	InputEvents();
	~InputEvents();

	void processEvents(function<void()> quitEvent);
};

#endif