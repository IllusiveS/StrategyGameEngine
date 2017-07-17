//
// Created by wysockipatryk on 2/28/17.
//

#include <TemplateManager/TemplateManager.h>
#include <fstream>
#include <GameElements/Modules/Module.h>
#include <GameElements/Unit/Unit.h>
#include <SDL/SDLContext.h>

int main (){
	SDLContext::Get().PrepareSDLContext();
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

	MapTile * road = new MapTile();
	road->setTemplateName("road");
	road->setModule("Core");
	road->setIsAttackableFunctionTemplateName("default");
	road->setIsEnterableFunctionTemplateName("default");
	road->setIsPassableFunctionTemplateName("default");
	road->setRetrieveMovementCostFunctionTemplateName("default");
	road->setTextureName("Road");
	manager.terrainManager.AddTemplatePair("road", road);

	Module * module = new Module();
	module->setAuthor("IllusiveS");
	module->setDescription("example mod description");
	module->setTemplateName("Core");
	module->setTemplateType("MODULE");
	module->setModule("Core");
	manager.moduleManager.AddTemplatePair("Core", module);

	Unit * unit = new Unit();
	unit->setModule("Core");
	unit->setHp(1);
	unit->setGlory(1);
	unit->setName("test unit");
	unit->setTemplateName("test_unit");
	manager.unitManager.AddTemplatePair(unit->getTemplateName(), unit);

//	std::ofstream moduleData("GameData/Modules/Core/module.json");
//	moduleData << module.serializeToJson();
	manager.SaveTemplates();
	return 0;
}