//
// Created by wysockipatryk on 4/17/17.
//

#include "Sprite.h"
#include <SDL_surface.h>

BaseModel::Sprite *BaseModel::Sprite::ReadSpriteFromFile(std::string location, SDL_Surface * surface) {
	return nullptr;
}

BaseModel::Sprite::Sprite(std::string name, SDL_Surface *) {

}

void BaseModel::Sprite::SetOrigin(Vector2D newOrigin) {
	origin = newOrigin;
}

void BaseModel::Sprite::SetSize(Vector2D size) {
	this->size = size;
}
