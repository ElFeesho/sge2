#include "graphics.hpp"
#include <SDL/SDL.h>

Graphics::Graphics()
{

}

Graphics::~Graphics()
{
	SDL_Quit();
}

void Graphics::openScreen(int w, int h)
{
	SDL_SetVideoMode(w, h, 0, SDL_SWSURFACE);
	this->w = w;
	this->h = h;
}

void Graphics::drawRect(short x, short y, short w, short h, int color)
{
	SDL_Rect rect = { (Sint16)x, (Sint16)y, (Uint16)w, (Uint16)h };
	SDL_FillRect(SDL_GetVideoSurface(), &rect, color);
}

void Graphics::render()
{
	SDL_Flip(SDL_GetVideoSurface());
}

int Graphics::width()
{
	return w;
}

int Graphics::height()
{
	return h;
}