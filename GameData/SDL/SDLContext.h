//
// Created by wysockipatryk on 4/18/17.
//

#ifndef STRATEGYGAME_SDLCONTEXT_H
#define STRATEGYGAME_SDLCONTEXT_H


#include <SDL_video.h>

class SDLContext {
public:
	static SDLContext& Get()
	{
		static SDLContext instance;
		return instance;
	}
private:
	SDLContext() {

	}

public:
	SDLContext(SDLContext const&) = delete;
	void operator=(SDLContext const&) = delete;
	void PrepareSDLContext();

	SDL_Window * GetWindow() {return window;};
	SDL_Surface * GetSurface() {return screenSurface;};

protected:
	bool init();

	SDL_Window * window = nullptr;
	SDL_Surface * screenSurface = nullptr;
};


#endif //STRATEGYGAME_SDLCONTEXT_H
