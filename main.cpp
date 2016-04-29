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

Engine &engine_from_luaState(lua_State *L)
{
    lua_getglobal(L, "__engine");
    Engine *engine = reinterpret_cast<Engine*>(lua_touserdata(L, -1));
    return *engine;
}

int main(int, char **)
{
	cout << "SGE2 Start" << endl;

    Engine engine;

	bool shouldQuit = false;
	
	auto quitFunctor = [&shouldQuit]() {
		shouldQuit = true;
	};

	map<string, lua_CFunction> graphicsMap = { 
		{	
			"openScreen", 
            [](lua_State *L) -> int
			{
                engine_from_luaState(L).graphics().openScreen(lua_tonumber(L, 1), lua_tonumber(L, 2));
				return 0;
			}
		}, 
		{
			"drawRect", 
            [](lua_State *L) -> int
			{
                Engine &engine = engine_from_luaState(L);

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

                engine.graphics().drawRect(x, y, w, h, colour);

				return 0;
			}
		}, 
		{
			"width", 
            [](lua_State *L) -> int
			{
                Engine &engine = engine_from_luaState(L);
                lua_pushnumber(L, engine.graphics().width());
				return 1;
			}
		}, 
		{
			"height", 
            [](lua_State *L) -> int
            {
                Engine &engine = engine_from_luaState(L);
                lua_pushnumber(L, engine.graphics().height());
				return 1;
			}
		}
	};

	map<string, lua_CFunction> inputMap = { 
		{	
			"mouseX", 
            [](lua_State *L) -> int
            {
                Engine &engine = engine_from_luaState(L);
                lua_pushinteger(L, engine.inputEvents().mouseX());
				return 1;
			}
		}, 
		{
			"mouseY", 
            [](lua_State *L) -> int
			{
                Engine &engine = engine_from_luaState(L);
                lua_pushinteger(L, engine.inputEvents().mouseY());
				return 1;
			}
		}, 
		{
			"mouseButton", 
            [](lua_State *L) -> int
            {
                Engine &engine = engine_from_luaState(L);
                lua_pushinteger(L, engine.inputEvents().mouseButton());
				return 1;
			}
		}
	};

    ScriptEnvironment scriptEnvironment{&engine};
    scriptEnvironment.bindClass("Graphics", graphicsMap);
    scriptEnvironment.bindClass("Input", inputMap);
    scriptEnvironment.loadFile("main.lua");

	while(!shouldQuit)
	{
        scriptEnvironment.update();
        engine.graphics().render();
        engine.inputEvents().processEvents(quitFunctor);
	}

	return 0;
}
