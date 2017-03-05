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
#include <boost/filesystem.hpp>

using json = nlohmann::json;
using namespace boost::filesystem;
using namespace std;

template<class Model>
class BaseTemplateManager {
protected:
	std::map<std::string, Model *> templatesMap;
	std::string templateDirectoryName;
public:
	virtual ~BaseTemplateManager() {
		for(auto itr = templatesMap.begin(); itr != templatesMap.end(); itr++) {
			std::pair<std::string, Model*> pair = *itr;
			Model * currentModel = pair.second;
			delete currentModel;
		}
		templatesMap.clear();
	}

	Model * GetTemplate(std::string templateName) {
		Model * foundModel = nullptr;

		foundModel = templatesMap[templateName];

		return foundModel;
	}

	std::vector<std::string> GetAllJsonsName(std::string directory) {
		std::vector<std::string> names;

		std::string gameDataDir = directory;
		path p = path(gameDataDir);

		try
		{
			if (exists(p))    // does p actually exist?
			{
				if (is_directory(p))      // is p a directory?
				{
					auto itr = directory_iterator(p);
					vector<path> files;
					copy(directory_iterator(p), directory_iterator(),
					     back_inserter(files));

					sort(files.begin(), files.end());

					for(auto i = files.begin(); i != files.end(); i++) {
						path currentPath = *i;
						if(is_directory(currentPath)){
							continue;
						}
						names.push_back(currentPath.string());
						//printf("[inf]_Found file %s\n", currentPath.string().c_str());
					}
				}
				else
					cout << p << " exists, but is neither a regular file nor a directory\n";
			}
			else
				cout << p << " does not exist\n";
		}

		catch (const filesystem_error& ex)
		{
			cout << ex.what() << '\n';
		}
		return names;
	}

	void ReadTemplatesFromJsons(std::string directory) {
		std::string formatedDir = directory + "/" + GetSubdirectory();
		std::vector<std::string> Jsons = GetAllJsonsName(formatedDir);
		for( auto itr = Jsons.begin(); itr != Jsons.end(); itr++) {
			std::string name = *itr;
			printf("[inf]_Reading template from %s\n", name.c_str());
			json j;

			std::ifstream ifs{name};

			auto parsed_json = json::parse(ifs);
			AddTemplate(parsed_json);
		}
	}

	virtual std::string GetTemplateType() = 0;
	virtual std::string GetSubdirectory() = 0;

	virtual void AddTemplate(json j) = 0;

	virtual void SaveTemplate(Model * model) = 0;

	void AddTemplatePair(std::string name, Model * model) {
		templatesMap.insert(
				std::pair<std::string, Model *>(name, model)
		);
	}

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
