#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include "inputevents.hpp"
#include "graphics.hpp"

class Engine 
{
public:
    explicit Engine();
    Engine(Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine &operator=(Engine&) = delete;
    Engine &operator=(Engine&&) = delete;
    Graphics &graphics();
    InputEvents &inputEvents();

private:
    Graphics gfx;
    InputEvents input;
};

#endif
