//
// Created by wysockipatryk on 2/28/17.
//

#include <TemplateManager/TemplateManager.h>
#include <fstream>
#include <GameElements/Modules/Module.h>

int main (){
	TemplateManager manager;
	//manager.ReadTemplates();
	MapTile tile;
	tile.setTemplateName("PLAINS");
	tile.setX(1);
	tile.setY(2);
	json tileJson = tile.SerializeToJson();

	Module module;
	module.setAuthor("IllusiveS");
	module.setDescription("example mod description");
	module.setName("example mod");
	module.setTemplateName("MODULE");

	std::ofstream moduleData("GameData/Modules/Core/module.json");
	moduleData << module.serializeToJson();

	std::ofstream out("GameData/Modules/Core/Json/MapTiles/testTile.json");
	out << tileJson;
	out.close();
	return 0;
}