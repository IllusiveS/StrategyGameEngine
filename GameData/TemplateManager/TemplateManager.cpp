//
// Created by wysockipatryk on 2/17/17.
//

#include "TemplateManager.h"
#include <dirent.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void TemplateManager::ReadTemplates() {
	DIR *pdir = NULL;
	struct dirent *pent = NULL;
	std::string gameDataDir = "./GameData/Modules/";
	pdir = opendir(gameDataDir.c_str());
	if(pdir == NULL) {
		printf("\nERROR! No modules found");
		exit (1);
	}

	while (pent = readdir (pdir)) // while there is still something in the directory to list
	{
		if (pent == NULL)
		{
			printf ("ERROR! pent could not be initialised correctly");
			exit (3);
		}
		std::string name(pent->d_name);
		if(strcmp(name.c_str(), ".") == 0 || strcmp(name.c_str(), "..") == 0)
		{
			//printf("excluded directory %s\n", name.c_str());
			continue;
		}
		// otherwise, it was initialised correctly. let's print it on the console:
		ReadSingleModule(pent->d_name, pent->d_name);
	}
}

void TemplateManager::ReadSingleModule(std::string moduleName,
                                       std::string directory) {
	printf("found directory %s \n", directory.c_str());
	terrainManager.ReadTemplatesFromModule(directory, moduleName);
}

void TemplateManager::SaveTemplates() {
	terrainManager.SaveTemplates();
}

const TerrainManager &TemplateManager::getTerrainManager() const {
	return terrainManager;
}

void TemplateManager::setTerrainManager(const TerrainManager &terrainManager) {
	TemplateManager::terrainManager = terrainManager;
}

const MapManager &TemplateManager::getMapManager() const {
	return mapManager;
}

void TemplateManager::setMapManager(const MapManager &mapManager) {
	TemplateManager::mapManager = mapManager;
}

const ArmyManager &TemplateManager::getArmyManager() const {
	return armyManager;
}

void TemplateManager::setArmyManager(const ArmyManager &armyManager) {
	TemplateManager::armyManager = armyManager;
}

const ModuleManager &TemplateManager::getModuleManager() const {
	return moduleManager;
}

void TemplateManager::setModuleManager(const ModuleManager &moduleManager) {
	TemplateManager::moduleManager = moduleManager;
}
