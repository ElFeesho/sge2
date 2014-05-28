#include "inputevents.hpp"

#include <SDL/SDL.h>
#include <functional>

using std::function;

InputEvents::InputEvents()
{

}

InputEvents::~InputEvents()
{

}

void InputEvents::processEvents(function<void()> quitEvent)
{
	SDL_Event event = { 0 };
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			quitEvent();
		}
	}
}