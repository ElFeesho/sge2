#ifndef __SCRIPTENGINE_HPP__
#define __SCRIPTENGINE_HPP__

#include <string>
#include <map>
#include <lua.hpp>

using std::string;
using std::map;

class ScriptEnvironment
{
public:
	ScriptEnvironment();
	~ScriptEnvironment();

	void bindClass(const string &className, map<string, lua_CFunction> functions);
	void loadFile(const string &scriptFile);
	void update();
private:
	lua_State *state;
};

#endif