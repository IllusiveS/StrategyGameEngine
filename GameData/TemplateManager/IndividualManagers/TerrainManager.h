//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_TERRAINMANAGER_H
#define STRATEGYGAME_TERRAINMANAGER_H

#include <dirent.h>
#include <map>
#include <string>
#include <GameElements/Map/MapTile.h>
#include "json/json.hpp"

using namespace BaseModel;
using json = nlohmann::json;

class TerrainManager {
protected:
	std::map<std::string, MapTile *> tiles;
	//TODO odczyt jsonów terenów z plików z katalogu
	//TODO dostęp do obiektów terenów ze stringa
public:
	MapTile * GetTemplate(std::string templateName);
	void ReadTemplatesFromModule(std::string directory, std::string module);
	void AddTemplate(json j);

	void ReadSingleTemplate(std::string directory, std::string moduleName);

	void SaveTemplates();
};


#endif //STRATEGYGAME_TERRAINMANAGER_H
