#ifndef __GRAPHICS_HPP__
#define __GRAPHICS_HPP__

class Graphics
{
public:
	Graphics();
	~Graphics();

	void openScreen(int w, int h);
	void drawRect(short x, short y, short w, short h, int color);
	void render();

	int width();
	int height();
private:
	int w, h;
};

#endif