#include <iostream>
#include "GameData/Unit/Unit.h"
#include <fstream>

int main() {
	std::cout << "Hello, World!" << std::endl;
	Unit u;
	u.setGlory(1);
	u.setHp(5);
	u.setName("unit");
	json j = u.SerializeToJson();
	std::ofstream o("pretty.json");
	o << std::setw(4) << j << std::endl;
	return 0;
}