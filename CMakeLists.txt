cmake_minimum_required(VERSION 3.29.5)

project(MysteryMaze
	VERSION 1.0.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)

# ${ } brackets for internal use
#creates a new variable set(VARIABLE_NAME VariableValue):
set(MYSTERY_MAZE_GAME_TARGET_NAME MysteryMazeGame)


#Imports the rest of the code in anothe CMakeLists.txt file located in subdirectory
add_subdirectory(MysteryMaze)
