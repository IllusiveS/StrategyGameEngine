cmake_minimum_required(VERSION 3.6)
project(StrategyGame)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/GameData)

set(SOURCE_FILES main.cpp Texture/Texture.cpp Texture/TextureManager.cpp)
add_executable(StrategyGame.exe ${SOURCE_FILES})
add_dependencies(StrategyGame.exe GameData)
target_link_libraries(StrategyGame.exe ${Boost_LIBRARIES} "${CMAKE_CURRENT_SOURCE_DIR}/../GameData/libGameData.a" ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${LUA_LIBRARIES} ${SDLMIXER2_LIBRARIES})