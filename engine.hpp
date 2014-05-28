#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

class Graphics;
class InputEvents;

class Engine 
{
public:
	static Engine *getInstance();
	static void shutdown();

	Graphics *getGraphics();
	InputEvents *getInputEvents();

private:
	Engine();
	~Engine();
	Graphics *graphics;
	InputEvents *input;

	static Engine *instance;
};

#endif