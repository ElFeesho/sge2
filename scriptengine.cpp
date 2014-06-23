#include "scriptengine.hpp"

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

ScriptEnvironment::ScriptEnvironment()
{
	state = lua_newstate([](void *ud, void *ptr, size_t osize, size_t nsize) -> void* {
		if(ptr == 0)
		{
			return malloc((osize+1) * nsize);
		}
		else
		{
			ptr = realloc(ptr, (osize+1) * nsize);
		}
		return ptr;
	}, 0);

	luaL_openlibs(state);
}

ScriptEnvironment::~ScriptEnvironment()
{
	lua_close(state);
}

void ScriptEnvironment::bindClass(const string &className, map<string, lua_CFunction> functions)
{
	lua_newtable(state);
	
	for(auto f : functions)
	{
		lua_pushcfunction(state, f.second);
		lua_setfield(state, 1, f.first.c_str());
	}

	lua_setglobal(state, className.c_str());
}

void ScriptEnvironment::loadFile(const string &scriptFile)
{

	int loadResult = luaL_loadfile(state, "main.lua");
	//lua_load(state, reader, (void*)(scriptFile.c_str()), "main", 0);
	
	if(loadResult == LUA_ERRSYNTAX)
	{
		cerr << "Failed to load syntax error " << scriptFile << endl;
		cerr << "Error: " << lua_tostring(state, 1) << endl;
	}
	else if(loadResult == LUA_ERRMEM)
	{
		cerr << "Memory alloc issues" << endl;
	}
	else if(loadResult == LUA_OK)
	{
		lua_call(state, 0, 0);
	}
}

void ScriptEnvironment::update()
{
	lua_getglobal(state, "update");
	lua_call(state, 0, 0);
}
