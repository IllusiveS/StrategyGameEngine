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

	MapTile *MapTile::CreateUnitFromJson(json j) {
		return nullptr;//TODO zrobić odczyt z JSONa
		//TODO zmienić nazwę metody na maptile
	}

	MapTile::MapTile() {
		templateType = "PLAINS";
	}

	json MapTile::serializeToJson() {
		json j = BasicElement::serializeToJson();
		j["x"] = x;
		j["y"] = y;
		j["armyTemplate"] = armyTemplate;
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

	const std::string &MapTile::getTemplateName() const {
		return BasicElement::getTemplateName();
	}

	void MapTile::setTemplateName(const std::string &templateName) {
		BasicElement::setTemplateName(templateName);
	}

	const std::string &MapTile::getTemplateType() const {
		return BasicElement::getTemplateType();
	}

	void MapTile::setTemplateType(const std::string &templateType) {
		BasicElement::setTemplateType(templateType);
	}

	const std::string &MapTile::getModule() const {
		return BasicElement::getModule();
	}

	void MapTile::setModule(const std::string &module) {
		BasicElement::setModule(module);
	}
}