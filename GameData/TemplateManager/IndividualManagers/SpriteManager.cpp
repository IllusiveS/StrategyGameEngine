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
	std::string spriteFilename = j["textureName"];
	float originX = j["origin"]["x"];
	float originY = j["origin"]["y"];

	Sprite * newSprite = Sprite::ReadSpriteFromFile(spriteFilename, SDLContext::Get().GetSurface());
	Vector2D newSpriteOrigin = Vector2D(originX, originY);
	newSprite->SetOrigin(newSpriteOrigin);
}

void SpriteManager::SaveTemplate(Sprite *model) {

}
