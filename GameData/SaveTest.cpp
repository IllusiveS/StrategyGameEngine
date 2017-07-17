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
	MapTile tile;
	tile.setTemplateName("plains");
	tile.setModule("Core");
	tile.setIsAttackableFunctionTemplateName("default");
	tile.setIsEnterableFunctionTemplateName("default");
	tile.setIsPassableFunctionTemplateName("default");
	tile.setRetrieveMovementCostFunctionTemplateName("default");
	tile.setTextureName("Plains");
	manager.terrainManager.AddTemplatePair("plains", &tile);

	Module module;
	module.setAuthor("IllusiveS");
	module.setDescription("example mod description");
	module.setTemplateName("Core");
	module.setTemplateType("MODULE");
	module.setModule("Core");
	manager.moduleManager.AddTemplatePair("Core", &module);

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