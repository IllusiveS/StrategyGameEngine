//
// Created by wysockipatryk on 2/17/17.
//

#include "MapTile.h"

namespace BaseModel {
	MapTile *MapTile::CreateUnitFromJson(json j) {
		return nullptr;//TODO zrobić odczyt z JSONa
		//TODO zmienić nazwę metody na maptile
	}

	MapTile::MapTile() : baseMovementCost(1) {
		templateType = "MAPTILE";
	}

	json MapTile::serializeToJson() {
		json j = BasicElement::serializeToJson();
		j["isPassableFunctionTemplateName"] = isPassableFunctionTemplateName;
		j["isEnterableFunctionTemplateName"] = isEnterableFunctionTemplateName;
		j["isAttackableFunctionTemplate"] = isAttackableFunctionTemplateName;
		j["retrieveMovementCostFunctionTemplateName"] = retrieveMovementCostFunctionTemplateName;
		j["textureName"] = textureName;
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

	const std::string &MapTile::getRetrieveMovementCostFunctionTemplateName() const {
		return retrieveMovementCostFunctionTemplateName;
	}

	void MapTile::setRetrieveMovementCostFunctionTemplateName(const std::string &retrieveMovementCostFunctionTemplateName) {
		MapTile::retrieveMovementCostFunctionTemplateName = retrieveMovementCostFunctionTemplateName;
	}

	int MapTile::getBaseMovementCost() const {
		return baseMovementCost;
	}

	void MapTile::setBaseMovementCost(int baseMovementCost) {
		MapTile::baseMovementCost = baseMovementCost;
	}

	const std::string &MapTile::getTextureName() const {
		return textureName;
	}

	void MapTile::setTextureName(const std::string &newTextureName) {
		textureName = newTextureName;
	}
}