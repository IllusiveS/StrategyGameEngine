//
// Created by wysockipatryk on 2/14/17.
//

#ifndef STRATEGYGAME_UNIT_H
#define STRATEGYGAME_UNIT_H

#include <string>
#include "lua.hpp"
#include "json/json.hpp"

namespace BaseModel {
	using json = nlohmann::json;

	class Unit {
	protected:
		int hp;
		int glory;
		std::string name;
		std::string templateName;
	public:
		const std::string &getTemplateName() const;

		void setTemplateName(const std::string &templateName);

		int getHp() const;

		void setHp(int hp);

		int getGlory() const;

		void setGlory(int glory);

		const std::string &getName() const;

		void setName(const std::string &name);

		static void ExportToLua(lua_State *L);

	protected:
		static Unit *CreateUnitFromJson(json j);//TODO odczytywanie z pliku
		Unit(json j);

	public:
		Unit();

		json SerializeToJson();
	};
}

#endif //STRATEGYGAME_UNIT_H
