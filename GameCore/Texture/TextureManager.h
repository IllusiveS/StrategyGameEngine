//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_TEXTUREMANAGER_H
#define STRATEGYGAME_TEXTUREMANAGER_H


#include "Texture.h"
#include <string>
#include <map>

class TextureManager {
	//TODO odczyt tekstur z katalogu z teksturami
	//TODO dostęp do tekstur na podstawie stringa
public:
	TextureManager();
	~TextureManager();

	Texture * GetTexture(std::string nazwaTextury) const;
private:
	std::map<std::string, Texture *> textures;

	void ReadTextures();
};


#endif //STRATEGYGAME_TEXTUREMANAGER_H
