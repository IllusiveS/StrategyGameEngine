//
// Created by wysockipatryk on 2/28/17.
//

#ifndef STRATEGYGAME_BASETEMPLATEMANAGER_H
#define STRATEGYGAME_BASETEMPLATEMANAGER_H

#include <string>
#include <map>
#include <json/json.hpp>
#include <vector>

using json = nlohmann::json;

template<class Model>
class BaseTemplateManager {
protected:
	std::map<std::string, Model *> templatesMap;
	std::string templateDirectoryName;
public:
	Model * GetTemplate(std::string templateName);
	std::vector<std::string> GetAllJsonsName(std::string directory);
	void ReadTemplatesFromJsons(std::string directory, std::vector<std::string> Jsons);

	virtual void AddTemplate(json j) = 0;
	virtual void SaveTemplates() = 0;
};


#endif //STRATEGYGAME_BASETEMPLATEMANAGER_H
