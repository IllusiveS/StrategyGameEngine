cmake_minimum_required(VERSION 3.6)
project(StrategyGame)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/GameData ~/Qt5.7.0/5.7/gcc_64)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH ~/Qt5.7.0/5.7/gcc_64)

find_package(Qt5Widgets)

set(SOURCE_FILES main.cpp mainwindow.cpp )

add_executable(StrategyGameEditor.exe ${SOURCE_FILES})
add_dependencies(StrategyGameEditor.exe GameData)
target_link_libraries(StrategyGameEditor.exe ${CMAKE_CURRENT_SOURCE_DIR}/../GameData/libGameData.a Qt5::Widgets  ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${LUA_LIBRARIES} ${SDLMIXER2_LIBRARIES})