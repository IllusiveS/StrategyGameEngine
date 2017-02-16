//
// Created by wysockipatryk on 2/14/17.
//

#ifndef STRATEGYGAME_UNIT_H
#define STRATEGYGAME_UNIT_H

#include <string>
#include "lua.hpp"

class Unit {
protected:
	int hp;
	int glory;
	std::string name;
	static void ExportToLua(lua_State * L);
};


#endif //STRATEGYGAME_UNIT_H
