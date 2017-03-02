//
// Created by wysockipatryk on 2/28/17.
//

#include "BaseTemplateManager.h"

template <class Model>
Model *BaseTemplateManager<Model>::GetTemplate(std::string templateName) {
	Model * foundModel;

	foundModel = templatesMap[templateName];

	return foundModel;
}

template <class Model>
std::vector<std::string> BaseTemplateManager<Model>::GetAllJsonsName(std::string directory) {
	return std::vector<std::string>();
}

template <class Model>
void BaseTemplateManager<Model>::ReadTemplatesFromJsons(std::string directory, std::vector<std::string> Jsons) {

}