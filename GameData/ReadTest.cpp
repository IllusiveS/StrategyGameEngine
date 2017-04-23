//
// Created by wysockipatryk on 2/28/17.
//

#include <TemplateManager/TemplateManager.h>
#include <fstream>
#include <GameElements/Modules/Module.h>
#include <SDL/SDLContext.h>

int main (){
	SDLContext::Get().PrepareSDLContext();
	TemplateManager manager;
	return 0;
}