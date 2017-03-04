//
// Created by wysockipatryk on 2/28/17.
//

#ifndef STRATEGYGAME_BASETEMPLATEMANAGER_H
#define STRATEGYGAME_BASETEMPLATEMANAGER_H

#include <string>
#include <map>
#include <json/json.hpp>
#include <vector>
#include <dirent.h>
#include <fstream>

using json = nlohmann::json;

template<class Model>
class BaseTemplateManager {
protected:
	std::map<std::string, Model *> templatesMap;
	std::string templateDirectoryName;
public:
	Model * GetTemplate(std::string templateName) {
		Model * foundModel = nullptr;

		foundModel = templatesMap[templateName];

		return foundModel;
	}

	std::vector<std::string> GetAllJsonsName(std::string directory) {
		std::vector<std::string> names;

		DIR *pdir = NULL;
		struct dirent *pent = NULL;
		std::string gameDataDir = directory;
		pdir = opendir(gameDataDir.c_str());
		if(pdir == NULL) {
			printf("Found no elements of type %s", GetTemplateType().c_str());
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
			names.push_back(name);
		}

		return names;
	}

	void ReadTemplatesFromJsons(std::string directory) {
		std::vector<std::string> Jsons = GetAllJsonsName(directory);
		for( auto itr = Jsons.begin(); itr != Jsons.end(); itr++) {
			std::string name = *itr;
			printf("Reading template from %s", name.c_str());
			json j;

			std::ifstream ifs{name};

			auto parsed_json = json::parse(ifs);
			AddTemplate(parsed_json);
		}
	}

	virtual std::string GetTemplateType() = 0;
	virtual std::string GetSubdirectory() = 0;

	virtual void AddTemplate(json j) = 0;

	virtual void ReadTeamplates() = 0;
	virtual void SaveTemplate(Model * model) = 0;
	virtual void SaveTemplates() {
		printf("Saving %s templates\n", GetTemplateType().c_str());
		for(auto itr = templatesMap.begin(); itr != templatesMap.end(); itr++) {
			std::pair<std::string, Model*> current = *itr;
			std::string templateType = GetTemplateType();
			std::string moduleName = current.second->template getModule();
			json j = current.second->template serializeToJson();
			{
				std::string thing = "./GameData/Modules/" + moduleName + "/" + GetSubdirectory() + current.first + ".json";
				printf("Saving %s\n", thing.c_str());
				std::ofstream o(thing);
				o << std::setw(4) << j << std::endl;
			}
		}
	}
};


#endif //STRATEGYGAME_BASETEMPLATEMANAGER_H
