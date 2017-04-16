//
// Created by wysockipatryk on 4/17/17.
//

#ifndef STRATEGYGAME_SPRITE_H
#define STRATEGYGAME_SPRITE_H

#include <json/json.hpp>
#include <GameElements/BasicElement.h>
#include <SDL_surface.h>

namespace BaseModel {
	using json = nlohmann::json;

	class Sprite : public BasicElement {
		public:
			static Sprite * ReadSpriteFromFile(std::string location);

		private:
			Sprite(std::string name, SDL_Surface*);

		protected:
			SDL_Surface * surface;
	};
}

#endif //STRATEGYGAME_SPRITE_H
