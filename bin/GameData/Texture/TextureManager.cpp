//
// Created by wysockipatryk on 2/17/17.
//

#include <iostream>
#include <SDL_image.h>
#include <lua.hpp>
#include "LuaBridge/LuaBridge.h"
#include "TextureManager.h"

Texture * TextureManager::GetTexture(std::string nazwaTextury) const {
	Texture * texToReturn = textures.at(nazwaTextury);
	return texToReturn;
}

TextureManager::TextureManager() {
	ReadTextures();
}

void TextureManager::ReadTextures() {
	using namespace luabridge;
	textures = std::map<std::string, Texture *>();
	lua_State *L = luaL_newstate();
	luaL_dofile(L, "Lua/Textures.lua");
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
	std::cout << "ReadingTextures" << std::endl;
	LuaRef texturesArray = getGlobal(L, "textures");
	if(texturesArray.isNil()) {
		printf("cant read textures array\n");
	}
	Iterator itr = Iterator(texturesArray);
	for( ; !itr.isNil(); ) {
		std::string texName = itr.key();
		std::string texPath = itr.value();
		SDL_Renderer * renderer; //TODO DODAJ RENDERER NORMALNY
		Texture * newTexture = new Texture(renderer);
		if(newTexture->loadFromFile(texPath)) {
			textures.insert ( std::pair<std::string, Texture *>(texName, newTexture) );
			printf("[suc]Created texture for %s \n", texPath.c_str());
		} else {
			printf("[err]Cant generate texture %s \n", texPath.c_str());
			delete newTexture;
		}
		++itr;
	}

}

TextureManager::~TextureManager() {
	for(auto itr = textures.begin(); itr != textures.end(); itr++) {
		itr->second->free();
	}
}