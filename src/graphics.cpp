#include "graphics.hpp"

Graphics::Graphics(GraphicsAdapter *graphics) : gfx(graphics)
{

}

void Graphics::openScreen(int w, int h)
{
    gfx->open(w, h);
    this->w = w;
	this->h = h;
}

void Graphics::drawRect(short x, short y, short w, short h, int color)
{
    gfx->drawRect(x, y, w, h, color);
}

void Graphics::render()
{
    gfx->render();
}

int Graphics::width()
{
	return w;
}

int Graphics::height()
{
	return h;
}
