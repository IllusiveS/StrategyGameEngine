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

json Unit::SerializeToJson() {
	json j;
	j["templateType"] = "UNIT";
	j["name"] = name;
	j["strength"] = hp;
	j["glory"] = glory;
	return j;
}

Unit::Unit(json j) {
	name = j["name"];
	hp = j["strength"];
	glory = j["glory"];
}

Unit *Unit::CreateUnitFromJson(json j) {
	if(j["templateType"] == "UNIT") {
		return new Unit(j);
	}
	return nullptr;
}

int Unit::getHp() const {
	return hp;
}

void Unit::setHp(int hp) {
	Unit::hp = hp;
}

int Unit::getGlory() const {
	return glory;
}

void Unit::setGlory(int glory) {
	Unit::glory = glory;
}

const std::string &Unit::getName() const {
	return name;
}

void Unit::setName(const std::string &name) {
	Unit::name = name;
}

Unit::Unit() {

}
