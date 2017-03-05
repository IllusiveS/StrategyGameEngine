//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_TERRAINMANAGER_H
#define STRATEGYGAME_TERRAINMANAGER_H

#include <dirent.h>
#include <map>
#include <string>
#include <GameElements/Map/MapTile.h>
#include <TemplateManager/BaseTemplateManager.h>
#include "json/json.hpp"

using namespace BaseModel;
using json = nlohmann::json;

class TerrainManager : public BaseTemplateManager<MapTile> {
protected:
	//TODO odczyt jsonów terenów z plików z katalogu
	//TODO dostęp do obiektów terenów ze stringa
public:
	std::string GetTemplateType() override;

	void AddTemplate(json j) override;

	void AddTemplate(std::string, MapTile *);

	void SaveTemplate(MapTile *model) override;

	std::string GetSubdirectory() override;
};


#endif //STRATEGYGAME_TERRAINMANAGER_H
