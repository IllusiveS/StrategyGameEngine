//
// Created by wysockipatryk on 7/17/17.
//

#include "UnitManager.h"

std::string UnitManager::GetTemplateType() {
	return "UNIT";
}

void UnitManager::AddTemplate(json j) {
	Unit * newTile = new Unit();
	std::string name = j["templateName"];
	newTile->setModule(j["module"]);
	newTile->setTemplateName(name);
	newTile->setTemplateType(j["templateType"]);
	templatesMap.insert(std::pair<std::string, Unit *>(name, newTile));
}

void UnitManager::SaveTemplate(Unit *model) {

}

std::string UnitManager::GetSubdirectory() {
	return "Json/Units/";
}

void UnitManager::AddTemplate(std::string name, Unit * tile) {
	templatesMap.insert(std::pair<std::string, Unit *>(name, tile));
}