#include "engine.hpp"

#include "graphics.hpp"
#include "inputevents.hpp"

Engine::Engine(GraphicsAdapter *gfxAdapter, InputAdapter *inputAdapter) : gfx{gfxAdapter}, input{inputAdapter}
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
