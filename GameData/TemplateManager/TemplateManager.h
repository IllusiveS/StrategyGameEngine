//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_TEMPLATEMANAGER_H
#define STRATEGYGAME_TEMPLATEMANAGER_H


#include <TemplateManager/IndividualManagers/TerrainManager.h>
#include <TemplateManager/IndividualManagers/MapManager.h>
#include <TemplateManager/IndividualManagers/ArmyManager.h>
#include <string>
#include <TemplateManager/IndividualManagers/ModuleManager.h>

class TemplateManager {
	//TODO odczyt danych z każdego katalogu z danymi (bendom mody)
public:
	TerrainManager terrainManager;
	MapManager mapManager;
	ArmyManager armyManager;
	ModuleManager moduleManager;

public:
	void ReadTemplates();
	void SaveTemplates();
	void ReadSingleModule(std::string moduleName, std::string directory);
};


#endif //STRATEGYGAME_TEMPLATEMANAGER_H
