//
// Created by wysockipatryk on 2/28/17.
//

#include <TemplateManager/TemplateManager.h>
#include <fstream>
#include <GameElements/Modules/Module.h>

int main (){
	TemplateManager manager;
	//manager.ReadTemplates();
	MapTile * tile = new MapTile();
	tile->setTemplateName("plains");
	tile->setX(1);
	tile->setY(2);
	tile->setArmyTemplate("");
	tile->setModule("Core");
	manager.terrainManager.AddTemplate("plains", tile);

	Module module;
	module.setAuthor("IllusiveS");
	module.setDescription("example mod description");
	module.setName("example mod");
	module.setTemplateName("MODULE");

//	std::ofstream moduleData("GameData/Modules/Core/module.json");
//	moduleData << module.serializeToJson();
	manager.SaveTemplates();
	return 0;
}