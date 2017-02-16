//
// Created by wysockipatryk on 2/14/17.
//

#include "Unit.h"
#include "LuaBridge/LuaBridge.h"

void Unit::ExportToLua(lua_State *L) {
	using namespace luabridge;
	getGlobalNamespace(L)
			.beginClass<Unit>("Unit")
					.addData("name", &Unit::name)
			.endClass()
	.endNamespace();
}