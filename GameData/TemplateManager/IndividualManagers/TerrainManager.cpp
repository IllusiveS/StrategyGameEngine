//
// Created by wysockipatryk on 2/17/17.
//

#include "TerrainManager.h"

MapTile *TerrainManager::GetTemplate(std::string templateName) {

	MapTile * mapTile = nullptr;

	for (auto const& x : tiles)
	{
		if(templateName == x.first) {
			mapTile = x.second;
		}
	}
	return mapTile;
}

void TerrainManager::ReadTemplatesFromModule(std::string module) {
	std::string modulePath = "GameData/Modules/" + module;
	printf("Reading terrain data from %s\n", modulePath.c_str());

}
