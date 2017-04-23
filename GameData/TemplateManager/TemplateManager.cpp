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
	printf("Looking for modules in %s \n", gameDataDir.c_str());
	if(pdir == NULL) {
		printf("ERROR! No modules found\n");
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
		ReadSingleModule(name, gameDataDir + name);
	}
}

void TemplateManager::ReadSingleModule(std::string moduleName,
                                       std::string directory) {
	//printf("found directory %s with module %s \n", directory.c_str(), moduleName.c_str());
	printf("[inf]READING MODULE %s\n", moduleName.c_str());
	moduleManager.ReadTemplatesFromJsons(directory);
	printf("[inf]READING MAPTILES FROM %s\n", moduleName.c_str());
	terrainManager.ReadTemplatesFromJsons(directory);
	printf("[inf]READING SPRITES FROM %s\n", moduleName.c_str());
	spriteManager.ReadTemplatesFromJsons(directory);
}

void TemplateManager::SaveTemplates() {
	moduleManager.SaveTemplates();
	terrainManager.SaveTemplates();
}

TemplateManager::TemplateManager(){
	ReadTemplates();
}