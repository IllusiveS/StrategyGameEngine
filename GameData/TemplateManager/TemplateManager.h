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
#include <TemplateManager/IndividualManagers/SpriteManager.h>
#include <TemplateManager/IndividualManagers/UnitManager.h>

class TemplateManager {
	//TODO odczyt danych z każdego katalogu z danymi (bendom mody)
public:
	TemplateManager();

	TerrainManager terrainManager;
	MapManager mapManager;
	ArmyManager armyManager;
	ModuleManager moduleManager;
	SpriteManager spriteManager;
	UnitManager unitManager;

public:
	void ReadTemplates();
	void SaveTemplates();
	void ReadSingleModule(std::string moduleName, std::string directory);
};


#endif //STRATEGYGAME_TEMPLATEMANAGER_H
