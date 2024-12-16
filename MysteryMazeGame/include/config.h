#pragma once
#include <string>

//this config file helps identify and find resource files location

std::string GetResourceDir()
{
//preprocess check
#ifdef NDEBUG //release mode
	return "assets/";
#else // debug mode
	return "C:/CMake_Projects/Uni_Coursework/CMake_learning_projects/MysteryMaze/MysteryMazeGame/assets/";
#endif
}
