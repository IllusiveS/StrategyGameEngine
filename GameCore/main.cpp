#include <iostream>
#include "GameElements/Unit/Unit.h"
#include <fstream>
#include <TemplateManager/TemplateManager.h>

int main() {
	std::cout << "Hello, World!" << std::endl;
	TemplateManager manager;
	manager.ReadTemplates();
	return 0;
}