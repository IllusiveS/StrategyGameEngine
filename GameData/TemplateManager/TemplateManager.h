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
	TerrainManager terrainManager;
	MapManager mapManager;
	ArmyManager armyManager;
	ModuleManager moduleManager;
public:
	const TerrainManager &getTerrainManager() const;
	void setTerrainManager(const TerrainManager &terrainManager);

	const MapManager &getMapManager() const;
	void setMapManager(const MapManager &mapManager);

	const ArmyManager &getArmyManager() const;
	void setArmyManager(const ArmyManager &armyManager);

	const ModuleManager &getModuleManager() const;
	void setModuleManager(const ModuleManager &moduleManager);

public:
	void ReadTemplates();
	void SaveTemplates();
	void ReadSingleModule(std::string moduleName, std::string directory);
};


#endif //STRATEGYGAME_TEMPLATEMANAGER_H
