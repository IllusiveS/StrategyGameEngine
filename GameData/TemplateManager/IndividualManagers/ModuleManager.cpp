//
// Created by wysockipatryk on 2/25/17.
//

#include "ModuleManager.h"

void ModuleManager::createModule(std::string templateName, ModuleCreationParameters params) {
	Module * newModule = new Module();
	newModule->setTemplateName(params.name);
	newModule->setAuthor(params.author);
	newModule->setDescription(params.description);
	newModule->setTemplateType("MODULE");
	templatesMap.insert(std::pair<std::string, Module*>(params.name, newModule));
}

ModuleManager::~ModuleManager() {

}

string ModuleManager::GetTemplateType() {
	return "MODULE";
}

string ModuleManager::GetSubdirectory() {
	return "";
}

void ModuleManager::AddTemplate(json j) {
	Module * mod = new Module();
	std::string name = j["templateName"];
	mod->setModule(name);
	mod->setTemplateName(name);
	mod->setAuthor(j["author"]);
	mod->setDescription(j["description"]);
	templatesMap.insert(
			std::pair<std::string, Module *>(name, mod)
	);
}

void ModuleManager::SaveTemplate(Module *model) {

}
