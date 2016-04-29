#pragma once

#include "graphicsadapter.hpp"
#include "inputadapter.hpp"
#include "inputevents.hpp"
#include "graphics.hpp"

class Engine 
{
public:
    explicit Engine(GraphicsAdapter *gfxAdapter, InputAdapter *inputAdapter);

    Graphics &graphics();
    InputEvents &inputEvents();

private:
    Graphics gfx;
    InputEvents input;
};

