//
// Created by wysockipatryk on 4/17/17.
//

#include <SDL/SDLContext.h>
#include "SpriteManager.h"

string SpriteManager::GetTemplateType() {
	return "SPRITE";
}

string SpriteManager::GetSubdirectory() {
	return "Assets/Textures";
}

void SpriteManager::AddTemplate(json j) {
	std::string spriteName = j["textureName"];
	std::string spriteFilename = j["filename"];
	std::string moduleName = j["module"];
	float originX = j["origin"]["x"];
	float originY = j["origin"]["y"];

	std::string filename = "./GameData/Modules/" + moduleName + "/" + GetSubdirectory() + "/" + spriteFilename;

	Sprite * newSprite = Sprite::ReadSpriteFromFile(filename, SDLContext::Get().GetSurface());
	if(newSprite == nullptr){
		printf("[err]cant read %s\n", filename.c_str());
	} else {
		printf("[suc]texture %s read\n", filename.c_str());
		Vector2D newSpriteOrigin = Vector2D(originX, originY);
		newSprite->SetOrigin(newSpriteOrigin);
	}
}

void SpriteManager::SaveTemplate(Sprite *model) {

}
