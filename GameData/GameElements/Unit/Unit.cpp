//
// Created by wysockipatryk on 2/14/17.
//

#include "Unit.h"
#include "LuaBridge/LuaBridge.h"

namespace BaseModel {
	void Unit::ExportToLua(lua_State *L) {
		using namespace luabridge;
		//TODO dokończyć export do luły
		getGlobalNamespace(L)
				.beginClass<Unit>("Unit")
				.addData("name", &Unit::name)
				.endClass()
				.endNamespace();
	}

	json Unit::serializeToJson() {
		json j = BasicElement::serializeToJson();
		j["templateType"] = "UNIT";
		j["templateName"] = templateName;
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
		if (j["templateType"] == "UNIT") {
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

	const std::string &Unit::getTemplateName() const {
		return templateName;
	}

	void Unit::setTemplateName(const std::string &templateName) {
		Unit::templateName = templateName;
	}
}