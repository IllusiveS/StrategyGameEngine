//
// Created by wysockipatryk on 4/17/17.
//

#ifndef STRATEGYGAME_SPRITEMANAGER_H
#define STRATEGYGAME_SPRITEMANAGER_H

#include <TemplateManager/BaseTemplateManager.h>
#include <GameElements/BasicElement.h>
#include <GameElements/Sprite/Sprite.h>

using namespace BaseModel;
using json = nlohmann::json;

class SpriteManager : public BaseTemplateManager<Sprite>{
public:
	string GetTemplateType() override;

	string GetSubdirectory() override;

	void AddTemplate(json j) override;

	void SaveTemplate(Sprite *model) override;
};


#endif //STRATEGYGAME_SPRITEMANAGER_H
