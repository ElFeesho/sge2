#include <iostream>
#include <string>
#include <functional>
#include <cstdlib>
#include <lua.hpp>
#include <SDL/SDL.h>
#include <map>
#include <fstream>
#include <cstdio>

#include "engine.hpp"
#include "graphics.hpp"
#include "inputevents.hpp"
#include "scriptengine.hpp"

using namespace std;


int main(int argc, char **argv)
{
	cout << "SGE2 Start" << endl;

	Engine::getInstance();
	
	ScriptEnvironment *scriptEnvironment = new ScriptEnvironment();

	bool shouldQuit = false;
	
	auto quitFunctor = [&shouldQuit]() {
		shouldQuit = true;
	};

	map<string, lua_CFunction> graphicsMap = { 
		{	
			"openScreen", 
			[](lua_State *L) -> int 
			{
				Engine::getInstance()->getGraphics()->openScreen(lua_tonumber(L, 1), lua_tonumber(L, 2));
				return 0;
			}
		}, 
		{
			"drawRect", 
			[](lua_State *L) -> int 
			{
				int x;
				int y;
				int w;
				int h;
				int colour;
				x = lua_tointeger(L, 1);
				y = lua_tointeger(L, 2);
				w = lua_tointeger(L, 3);
				h = lua_tointeger(L, 4);
				colour = lua_tointeger(L, 5);
				Engine::getInstance()->getGraphics()->drawRect(x, y, w, h, colour);

				return 0;
			}
		}, 
		{
			"width", 
			[](lua_State *L) -> int 
			{
				lua_pushnumber(L, Engine::getInstance()->getGraphics()->width());
				return 1;
			}
		}, 
		{
			"height", 
			[](lua_State *L) -> int 
			{
				lua_pushnumber(L, Engine::getInstance()->getGraphics()->height());
				return 1;
			}
		}
	};

	map<string, lua_CFunction> inputMap = { 
		{	
			"mouseX", 
			[](lua_State *L) -> int 
			{
				lua_pushinteger(L, Engine::getInstance()->getInputEvents()->mouseX());
				return 1;
			}
		}, 
		{
			"mouseY", 
			[](lua_State *L) -> int 
			{

				lua_pushinteger(L, Engine::getInstance()->getInputEvents()->mouseY());
				return 1;
			}
		}, 
		{
			"mouseButton", 
			[](lua_State *L) -> int 
			{
				lua_pushinteger(L, Engine::getInstance()->getInputEvents()->mouseButton());
				return 1;
			}
		}
	};

	scriptEnvironment->bindClass("Graphics", graphicsMap);
	scriptEnvironment->bindClass("Input", inputMap);
	scriptEnvironment->loadFile("main.lua");

	while(!shouldQuit)
	{
		scriptEnvironment->update();
		Engine::getInstance()->getGraphics()->render();
		Engine::getInstance()->getInputEvents()->processEvents(quitFunctor);
	}

	Engine::shutdown();
	delete scriptEnvironment;

	return 0;
}