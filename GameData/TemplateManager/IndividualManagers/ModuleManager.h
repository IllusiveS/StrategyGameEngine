//
// Created by wysockipatryk on 2/25/17.
//

#ifndef STRATEGYGAME_MODULEMANAGER_H
#define STRATEGYGAME_MODULEMANAGER_H

#include <set>
#include <string>
#include <TemplateManager/BaseTemplateManager.h>
#include "GameElements/Modules/Module.h"

using namespace BaseModel;

class ModuleManager : public BaseTemplateManager<Module> {
public:
	void createModule(std::string templateName, ModuleCreationParameters params);

	~ModuleManager();

	string GetTemplateType() override;

	string GetSubdirectory() override;

	void AddTemplate(json j) override;

	void SaveTemplate(Module *model) override;
};


#endif //STRATEGYGAME_MODULEMANAGER_H
