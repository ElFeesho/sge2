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

int InputEvents::mouseX()
{
	int x;
	SDL_GetMouseState(&x, 0);
	return x;
}

int InputEvents::mouseY()
{
	int y;
	SDL_GetMouseState(0, &y);
	return y;
}

int InputEvents::mouseButton()
{
	return SDL_GetMouseState(0, 0);
}