#using variable we created or was created for us in main CMakeLists.txt file
#this CMake list determines which source file will be used for the project
#caution - reference current directory path /src/main.cpp, or it will output an error
add_executable(${MYSTERY_MAZE_GAME_TARGET_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)