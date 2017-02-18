//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_TEMPLATEMANAGER_H
#define STRATEGYGAME_TEMPLATEMANAGER_H


#include <TemplateManager/IndividualManagers/TextureManager.h>
#include <TemplateManager/IndividualManagers/TerrainManager.h>
#include <TemplateManager/IndividualManagers/MapManager.h>
#include <TemplateManager/IndividualManagers/ArmyManager.h>
#include <string>

class TemplateManager {
	//TODO odczyt danych z każdego katalogu z danymi (bendom mody)
	TextureManager textureManager;
	TerrainManager terrainManager;
	MapManager mapManager;
	ArmyManager armyManager;
	//TODO dostęp do informacji o modach?
public:
	void ReadTemplates();
	void ReadSingleTemplate(std::string directory);
};


#endif //STRATEGYGAME_TEMPLATEMANAGER_H
