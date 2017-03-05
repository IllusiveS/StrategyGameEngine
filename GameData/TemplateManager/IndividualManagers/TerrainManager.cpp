//
// Created by wysockipatryk on 2/17/17.
//

#include "TerrainManager.h"

std::string TerrainManager::GetTemplateType() {
	return "MAPTILE";
}

void TerrainManager::AddTemplate(json j) {
	MapTile * newTile = new MapTile();
	std::string name = j["templateName"];
	newTile->setModule(j["module"]);
	newTile->setTemplateName(name);
	newTile->setTemplateType(j["templateType"]);
	newTile->setArmyTemplate(j["armyTemplate"]);
	newTile->setX(j["x"]);
	newTile->setY(j["y"]);
	templatesMap.insert(std::pair<std::string, MapTile *>(name, newTile));
}

void TerrainManager::SaveTemplate(MapTile *model) {

}

std::string TerrainManager::GetSubdirectory() {
	return "Json/MapTiles/";
}

void TerrainManager::AddTemplate(std::string name, MapTile * tile) {
	templatesMap.insert(std::pair<std::string, MapTile *>(name, tile));
}
