#pragma once

class GraphicsAdapter
{
public:
    virtual ~GraphicsAdapter() {}

    virtual void open(unsigned int width, unsigned int height) = 0;
    virtual void render() = 0;
    virtual void drawRect(int x, int y, int w, int h, unsigned int colour) = 0;
};
