cmake_minimum_required(VERSION 3.29.5)

project(MysteryMaze
	VERSION 1.0.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)


#Internal functionality which will allow us to fetch things from somewhere else
include(FetchContent)

#define SFML library varible name because we will use its name to fetch from git
set(SFML_LIBR_NAME SFML)

FetchContent_Declare(
	${SFML_LIBR_NAME}
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 2.6.2

	#specify that we don't want to have just a shallow copy of repository
	#we do copy of all dependent libraries instead of just referencing
	GIT_SHALLOW FALSE
)

#make SFML available to our project
FetchContent_MakeAvailable(${SFML_LIBR_NAME})

# Set output directories 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ${ } brackets for internal use
#creates a new variable set(VARIABLE_NAME VariableValue), defines a new target
set(MYSTERY_MAZE_ENGINE_TARGET_NAME MysteryMazeEngine)
set(MYSTERY_MAZE_GAME_TARGET_NAME MysteryMazeGame)

#Imports the rest of the code in another CMakeLists.txt file located in subdirectory
add_subdirectory(MysteryMazeEngine)
add_subdirectory(MysteryMazeGame)


