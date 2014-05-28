#include "engine.hpp"

#include "graphics.hpp"
#include "inputevents.hpp"

Engine::Engine()
{
	graphics = new Graphics();
	input = new InputEvents();
}

Engine::~Engine()
{
	delete graphics;
	delete input;
}

Graphics *Engine::getGraphics()
{
	return graphics;
}

InputEvents *Engine::getInputEvents()
{
	return input;
}

Engine *Engine::getInstance()
{
	if(Engine::instance == 0)
	{
		Engine::instance = new Engine();
	}
}

void Engine::shutdown()
{
	delete Engine::instance;
}

Engine *Engine::instance = 0;