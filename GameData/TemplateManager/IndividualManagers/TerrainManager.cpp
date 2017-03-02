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

void TerrainManager::ReadTemplatesFromModule(std::string directory, std::string module) {
	std::string modulePath = directory;
	printf("Reading terrain data from %s\n", modulePath.c_str());

	DIR *pdir = NULL;
	struct dirent *pent = NULL;
	std::string gameDataDir = directory + "";
	pdir = opendir(gameDataDir.c_str());
	if(pdir == NULL) {
		printf("No terrain tiles found\n");
		return;
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
		ReadSingleTemplate(pent->d_name, gameDataDir + pent->d_name);
	}
}

void TerrainManager::AddTemplate(json j) {

}

void TerrainManager::ReadSingleTemplate(std::string directory, std::string moduleName) {

}

void TerrainManager::SaveTemplates() {

}
