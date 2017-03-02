//
// Created by wysockipatryk on 2/25/17.
//

#include "ModuleManager.h"

void ModuleManager::createModule(std::string templateName, ModuleCreationParameters params) {
	Module * newModule = new Module();
	newModule->setName(params.name);
	newModule->setName(params.author);
	newModule->setDescription(params.description);
	modules.insert(newModule);
}

ModuleManager::~ModuleManager() {

}

void ModuleManager::SaveModules() {

}
