//
// Created by wysockipatryk on 2/17/17.
//

#include "Army.h"

int Army::getX() const {
	return x;
}

void Army::setX(int x) {
	Army::x = x;
}

int Army::getY() const {
	return y;
}

void Army::setY(int y) {
	Army::y = y;
}

int Army::getMov() const {
	return mov;
}

void Army::setMov(int mov) {
	Army::mov = mov;
}

int Army::getMaxMov() const {
	return maxMov;
}

void Army::setMaxMov(int maxMov) {
	Army::maxMov = maxMov;
}

const std::string &Army::getName() const {
	return name;
}

void Army::setName(const std::string &name) {
	Army::name = name;
}

const std::string &Army::getTemplateName() const {
	return templateName;
}

void Army::setTemplateName(const std::string &templateName) {
	Army::templateName = templateName;
}

const std::string &Army::getTemplateType() const {
	return templateType;
}

void Army::setTemplateType(const std::string &templateType) {
	Army::templateType = templateType;
}

void Army::ExportToLua(lua_State *L) {
	//TODO export do luły
}

json Army::SerializeToJson() {
	json j;
	j["x"] = x;
	j["y"] = y;
	j["mov"] = mov;
	j["maxMov"] = maxMov;
	j["name"] = name;
	j["templateName"] = templateName;
	j["templateType"] = templateType;
	return j;
}
