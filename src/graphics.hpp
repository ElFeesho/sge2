#ifndef __GRAPHICS_HPP__
#define __GRAPHICS_HPP__

#include "graphicsadapter.hpp"

class Graphics
{
public:
    Graphics(GraphicsAdapter *graphcis);
    Graphics(Graphics&) = delete;
    Graphics(Graphics &&) = delete;

    Graphics& operator=(Graphics&) = delete;
    Graphics& operator=(Graphics &&) = delete;

	void openScreen(int w, int h);
	void drawRect(short x, short y, short w, short h, int color);
	void render();

	int width();
	int height();
private:
    GraphicsAdapter *gfx;
    int w;
    int h;
};

#endif
