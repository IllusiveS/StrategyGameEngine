cmake_minimum_required(VERSION 3.6)
project(StrategyGame)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")

set(SOURCE_FILES GameElements/Unit/Unit.cpp TemplateManager/TemplateManager.cpp TemplateManager/TemplateManager.h TemplateManager/IndividualManagers/TerrainManager.cpp TemplateManager/IndividualManagers/TerrainManager.h TemplateManager/IndividualManagers/MapManager.cpp TemplateManager/IndividualManagers/MapManager.h TemplateManager/IndividualManagers/ArmyManager.cpp TemplateManager/IndividualManagers/ArmyManager.h GameElements/Map/Map.cpp GameElements/Map/Map.h GameElements/Map/MapTile.cpp GameElements/Map/MapTile.h GameElements/Army/Army.cpp GameElements/Army/Army.h TemplateManager/IndividualManagers/ModuleManager.cpp TemplateManager/IndividualManagers/ModuleManager.h GameElements/Modules/Module.cpp GameElements/Modules/Module.h GameElements/BasicElement.cpp GameElements/BasicElement.h TemplateManager/BaseTemplateManager.cpp TemplateManager/BaseTemplateManager.h GameElements/Sprite/Sprite.cpp GameElements/Sprite/Sprite.h TemplateManager/IndividualManagers/SpriteManager.cpp TemplateManager/IndividualManagers/SpriteManager.h)

add_library(GameDataObj OBJECT ${SOURCE_FILES})

add_library(GameData $<TARGET_OBJECTS:GameDataObj>)

add_executable(GameDataSaveTest.exe $<TARGET_OBJECTS:GameDataObj> SaveTest.cpp)
add_executable(GameDataReadTest.exe $<TARGET_OBJECTS:GameDataObj> ReadTest.cpp)

add_dependencies(GameDataSaveTest.exe GameData)
add_dependencies(GameDataReadTest.exe GameData)

target_link_libraries(GameDataSaveTest.exe ${Boost_LIBRARIES} "${CMAKE_CURRENT_SOURCE_DIR}/libGameData.a" ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${LUA_LIBRARIES} ${SDLMIXER2_LIBRARIES})
target_link_libraries(GameDataReadTest.exe ${Boost_LIBRARIES} "${CMAKE_CURRENT_SOURCE_DIR}/libGameData.a" ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${LUA_LIBRARIES} ${SDLMIXER2_LIBRARIES})
