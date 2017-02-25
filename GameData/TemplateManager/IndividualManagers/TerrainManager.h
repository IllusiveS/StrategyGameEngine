//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_TERRAINMANAGER_H
#define STRATEGYGAME_TERRAINMANAGER_H

#include <dirent.h>
#include <map>
#include <string>
#include <GameElements/Map/MapTile.h>

using namespace BaseModel;

class TerrainManager {
protected:
	std::map<std::string, MapTile *> tiles;
	//TODO odczyt jsonów terenów z plików z katalogu
	//TODO dostęp do obiektów terenów ze stringa
public:
	MapTile * GetTemplate(std::string templateName);
	void ReadTemplatesFromModule(std::string module);
};


#endif //STRATEGYGAME_TERRAINMANAGER_H
