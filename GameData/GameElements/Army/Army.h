//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_ARMY_H
#define STRATEGYGAME_ARMY_H

#include <string>
#include <lua.h>
#include "json/json.hpp"

using json = nlohmann::json;

class Army {
	int x;
	int y;
	int mov;
	int maxMov;
	std::string name;
	std::string templateName;
	std::string templateType;
public:
	int getX() const;
	void setX(int x);

	int getY() const;
	void setY(int y);

	int getMov() const;
	void setMov(int mov);

	int getMaxMov() const;
	void setMaxMov(int maxMov);

	const std::string &getName() const;
	void setName(const std::string &name);

	const std::string &getTemplateName() const;
	void setTemplateName(const std::string &templateName);

	const std::string &getTemplateType() const;
	void setTemplateType(const std::string &templateType);

	static void ExportToLua(lua_State * L);
	json SerializeToJson();
};


#endif //STRATEGYGAME_ARMY_H
