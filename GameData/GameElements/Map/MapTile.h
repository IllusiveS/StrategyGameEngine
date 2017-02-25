//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_MAPTILE_H
#define STRATEGYGAME_MAPTILE_H

#include <string>
#include "json/json.hpp"

using json = nlohmann::json;

namespace BaseModel {
	class MapTile {
	protected:
		int x;
		int y;
		std::string isPassableFunction;
		std::string isEnterableFunction;
	public:
		const std::string &getIsPassableFunction() const;

		void setIsPassableFunction(const std::string &isPassableFunction);

		const std::string &getIsEnterableFunction() const;

		void setIsEnterableFunction(const std::string &isEnterableFunction);

		const std::string &getIsAttackableFunction() const;

		void setIsAttackableFunction(const std::string &isAttackableFunction);

	protected:
		std::string isAttackableFunction;
		std::string armyTemplate;
		std::string templateName;
		std::string templateType;

	public:
		int getX() const;

		void setX(int x);

		int getY() const;

		void setY(int y);

		const std::string &getArmyTemplate() const;

		void setArmyTemplate(const std::string &armyTemplate);

		const std::string &getTemplateName() const;

		void setTemplateName(const std::string &templateName);

		const std::string &getTemplateType() const;

		void setTemplateType(const std::string &templateType);

	public:
		static MapTile *CreateUnitFromJson(json j);//TODO odczytywanie z JSONa
		MapTile();//TODO może jakiś konstruktor z parametrami?
		json SerializeToJson();
	};
}

#endif //STRATEGYGAME_MAPTILE_H
