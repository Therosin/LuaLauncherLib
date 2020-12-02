#pragma once
#pragma comment (lib, "Lua.lib")
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <iostream>
#include <windows.h>

#define MAX_FILEPATH_LENGTH 255

int main(int argc, char** argv)
{
	lua_State* L;

	//init lua interpreter
	L = luaL_newstate();

	//load lua base libs
	luaL_openlibs(L);

	char filepath[MAX_FILEPATH_LENGTH];
	strcpy_s(filepath, "app/main.lua");
	if (argc == 2)
	{
		printf("\n > File name passed, running: %s", argv[1]);
		strcpy_s(filepath, argv[1]);
	}
	else
	{
		printf("\n > No file name, running app/main.lua\n");
	}
	try
	{
		luaL_dofile(L, filepath);
	}

	catch (const std::exception e)
	{
		printf("\n > Lua failed with exception: %s", e.what());
	}

	//Dealloc all associated space
	lua_close(L);
	//exit
	printf("\n > Press enter to exit...");
	getchar();

	return 0;
}