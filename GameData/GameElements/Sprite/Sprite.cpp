//
// Created by wysockipatryk on 4/17/17.
//

#include "Sprite.h"
#include <SDL_surface.h>
#include <SDL_image.h>

BaseModel::Sprite *BaseModel::Sprite::ReadSpriteFromFile(std::string location, SDL_Surface * surface) {
	Sprite * newSprite = nullptr;

	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( location.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", location.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, surface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", location.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );

		newSprite = new Sprite();
		newSprite->SetSurface(optimizedSurface);
	}



	return newSprite;
}

BaseModel::Sprite::Sprite() {

}

void BaseModel::Sprite::SetOrigin(Vector2D newOrigin) {
	origin = newOrigin;
}

void BaseModel::Sprite::SetSize(Vector2D size) {
	this->size = size;
}

void BaseModel::Sprite::SetSurface(SDL_Surface *newSurface) {
	surface = newSurface;
}
