//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_MAPTILE_H
#define STRATEGYGAME_MAPTILE_H

#include <string>
#include "json/json.hpp"

using json = nlohmann::json;

class MapTile {
protected:
	int x;
	int y;
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
	static MapTile * CreateUnitFromJson(json j);//TODO odczytywanie z JSONa
	MapTile();//TODO może jakiś konstruktor z parametrami?
	json SerializeToJson();
};


#endif //STRATEGYGAME_MAPTILE_H
