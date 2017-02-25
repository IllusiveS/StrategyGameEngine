//
// Created by wysockipatryk on 2/17/17.
//

#include <SDL_image.h>
#include "Texture.h"

Texture::Texture(SDL_Renderer * renderer) : renderer(renderer), mWidth(0), mHeight(0), mTexture(NULL)
{

}

Texture::~Texture()
{
	//Deallocate
	free();
}

bool Texture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void Texture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Texture::render( int x, int y )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x-(mWidth/2), y-(mHeight/2), mWidth, mHeight };
	SDL_RenderCopy( renderer, mTexture, NULL, &renderQuad );
}
void Texture::render( int x, int y, int frameW, int frameH, SDL_Rect Animrect  )
{
	Animrect.w = frameW;
	Animrect.h = frameH;

	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x-(frameW/2), y-(frameH/2), frameW, frameH };
	SDL_RenderCopy( renderer, mTexture, &Animrect, &renderQuad );
}

int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}