//
// Created by wysockipatryk on 7/17/17.
//

#ifndef STRATEGYGAME_UNITMANAGER_H
#define STRATEGYGAME_UNITMANAGER_H

#include <GameElements/Unit/Unit.h>
#include <TemplateManager/BaseTemplateManager.h>

using namespace BaseModel;
using json = nlohmann::json;

class UnitManager : public BaseTemplateManager<Unit> {
public:
	std::string GetTemplateType() override;

	void AddTemplate(json j) override;

	void AddTemplate(std::string, Unit *);

	void SaveTemplate(Unit *model) override;

	std::string GetSubdirectory() override;
};


#endif //STRATEGYGAME_UNITMANAGER_H
