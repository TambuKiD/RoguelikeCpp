cmake_minimum_required(VERSION 3.19)
project(roguelike)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")

# find library
find_package(BearLibTerminal REQUIRED)
# include
include_directories(SYSTEM ${BLT_INCLUDE_DIRS})
# link

add_executable(roguelike src/main.cpp src/GameObject.cpp src/GameObject.h src/MovableObject.h src/Character.h src/Hero.cpp src/Hero.h src/ActionAnalyzer.cpp src/ActionAnalyzer.h src/LevelMap.cpp src/LevelMap.h src/Command/ICommand.h)


target_link_libraries(${PROJECT_NAME} ${BLT_LIBRARIES})
file(COPY ${BLT_LIBRARY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
