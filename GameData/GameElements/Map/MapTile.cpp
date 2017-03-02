//
// Created by wysockipatryk on 2/17/17.
//

#include "MapTile.h"

namespace BaseModel {
	int MapTile::getX() const {
		return x;
	}

	void MapTile::setX(int x) {
		MapTile::x = x;
	}

	int MapTile::getY() const {
		return y;
	}

	void MapTile::setY(int y) {
		MapTile::y = y;
	}

	const std::string &MapTile::getArmyTemplate() const {
		return armyTemplate;
	}

	void MapTile::setArmyTemplate(const std::string &armyTemplate) {
		MapTile::armyTemplate = armyTemplate;
	}

	const std::string &MapTile::getTemplateName() const {
		return templateName;
	}

	void MapTile::setTemplateName(const std::string &templateName) {
		MapTile::templateName = templateName;
	}

	const std::string &MapTile::getTemplateType() const {
		return templateType;
	}

	void MapTile::setTemplateType(const std::string &templateType) {
		MapTile::templateType = templateType;
	}

	MapTile *MapTile::CreateUnitFromJson(json j) {
		return nullptr;//TODO zrobić odczyt z JSONa
		//TODO zmienić nazwę metody na maptile
	}

	MapTile::MapTile() {

	}

	json MapTile::SerializeToJson() {
		json j;
		j["x"] = x;
		j["y"] = y;
		j["armyTemplate"] = armyTemplate;
		j["templateName"] = templateName;
		j["templateType"] = "MAPTILE";
		return j;
	}

	const std::string &MapTile::getIsPassableFunctionTemplateName() const {
		return isPassableFunctionTemplateName;
	}

	void MapTile::setIsPassableFunctionTemplateName(const std::string &isPassableFunction) {
		MapTile::isPassableFunctionTemplateName = isPassableFunction;
	}

	const std::string &MapTile::getIsEnterableFunctionTemplateName() const {
		return isEnterableFunctionTemplateName;
	}

	void MapTile::setIsEnterableFunctionTemplateName(const std::string &isEnterableFunction) {
		MapTile::isEnterableFunctionTemplateName = isEnterableFunction;
	}

	const std::string &MapTile::getIsAttackableFunctionTemplateName() const {
		return isAttackableFunctionTemplateName;
	}

	void MapTile::setIsAttackableFunctionTemplateName(const std::string &isAttackableFunction) {
		MapTile::isAttackableFunctionTemplateName = isAttackableFunction;
	}
}