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
	tile->setModule("Core");
	tile->setIsAttackableFunctionTemplateName("default");
	tile->setIsEnterableFunctionTemplateName("default");
	tile->setIsPassableFunctionTemplateName("default");
	tile->setRetrieveMovementCostFunctionTemplateName("default");
	tile->setTextureName("Plains");
	manager.terrainManager.AddTemplatePair("plains", tile);

	Module * module = new Module();
	module->setAuthor("IllusiveS");
	module->setDescription("example mod description");
	module->setTemplateName("Core");
	module->setTemplateType("MODULE");
	module->setModule("Core");
	manager.moduleManager.AddTemplatePair("Core", module);


//	std::ofstream moduleData("GameData/Modules/Core/module.json");
//	moduleData << module.serializeToJson();
	manager.SaveTemplates();
	return 0;
}