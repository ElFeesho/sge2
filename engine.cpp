#include "engine.hpp"

#include "graphics.hpp"
#include "inputevents.hpp"

Engine::Engine()
{
}

Graphics &Engine::graphics()
{
    return gfx;
}

InputEvents &Engine::inputEvents()
{
	return input;
}
