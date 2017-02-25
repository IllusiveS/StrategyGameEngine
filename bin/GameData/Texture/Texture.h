//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_TEXTURE_H
#define STRATEGYGAME_TEXTURE_H

#include <string>
#include <SDL_render.h>

//Texture wrapper class
class Texture
{
public:
	//Initializes variables
	Texture(SDL_Renderer * renderer);

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	bool loadFromFile( std::string path );

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render( int x, int y );

	void render( int x, int y, int width, int height,  SDL_Rect Animrect  );

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
	SDL_Renderer * renderer;
};


#endif //STRATEGYGAME_TEXTURE_H
