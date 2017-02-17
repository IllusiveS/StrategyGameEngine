cmake_minimum_required(VERSION 3.6)
project(StrategyGame)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(GameData GameElements/Unit/Unit.cpp TemplateManager/TemplateManager.cpp TemplateManager/TemplateManager.h TemplateManager/IndividualManagers/TerrainManager.cpp TemplateManager/IndividualManagers/TerrainManager.h TemplateManager/IndividualManagers/MapManager.cpp TemplateManager/IndividualManagers/MapManager.h TemplateManager/IndividualManagers/TextureManager.cpp TemplateManager/IndividualManagers/TextureManager.h TemplateManager/IndividualManagers/ArmyManager.cpp TemplateManager/IndividualManagers/ArmyManager.h Texture/Texture.cpp Texture/Texture.h GameElements/Map/Map.cpp GameElements/Map/Map.h GameElements/Map/MapTile.cpp GameElements/Map/MapTile.h GameElements/Army/Army.cpp GameElements/Army/Army.h)