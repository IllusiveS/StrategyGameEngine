#include <iostream>
#include "GameElements/Unit/Unit.h"
#include <fstream>
#include <TemplateManager/TemplateManager.h>

using json = nlohmann::json;

int main() {
	TemplateManager manager;
	manager.ReadTemplates();
	MapTile tile;
	tile.setTemplateName("PLAINS");
	tile.setX(1);
	tile.setY(2);
	json tileJson = tile.SerializeToJson();

	std::ofstream out("GameData/Modules/Core/Json/MapTiles/testTile.json");
	out << tileJson;
	out.close();
	return 0;
}