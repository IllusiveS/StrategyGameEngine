//
// Created by wysockipatryk on 2/25/17.
//

#ifndef STRATEGYGAME_MODULEMANAGER_H
#define STRATEGYGAME_MODULEMANAGER_H

#include <set>
#include <string>
#include "GameElements/Modules/Module.h"

using namespace BaseModel;

class ModuleManager {
protected:
	std::set<Module *> modules;
public:
	void createModule(std::string templateName, ModuleCreationParameters params);

	~ModuleManager();

	void SaveModules();
};


#endif //STRATEGYGAME_MODULEMANAGER_H
