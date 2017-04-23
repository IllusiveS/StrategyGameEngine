//
// Created by wysockipatryk on 4/17/17.
//

#ifndef STRATEGYGAME_SPRITE_H
#define STRATEGYGAME_SPRITE_H

#include <json/json.hpp>
#include <GameElements/BasicElement.h>
#include <Math/Vector2D.h>

class SDL_Surface;

namespace BaseModel {
	using json = nlohmann::json;

	class Sprite : public BasicElement {
		public:
			static Sprite * ReadSpriteFromFile(std::string location, SDL_Surface * surface);

		private:
			Sprite(std::string name, SDL_Surface*);

		public:
			void SetOrigin(Vector2D newOrigin);
			void SetSize(Vector2D size);

		protected:
			Vector2D origin;
			Vector2D size;
			SDL_Surface * surface;
	};
}

#endif //STRATEGYGAME_SPRITE_H
