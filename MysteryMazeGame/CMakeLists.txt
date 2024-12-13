#using variable we created or was created for us in main CMakeLists.txt file
#this CMake list determines which source file will be used for the project
#caution - reference current directory path /src/main.cpp, or it will output an error
add_executable(${MYSTERY_MAZE_GAME_TARGET_NAME}
	#tells to includr game source file
	${CMAKE_CURRENT_SOURCE_DIR}/include/GameFramework/GameApplication.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/GameFramework/GameApplication.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/ghost/Ghost.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/ghost/Ghost.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/player/PlayerGhost.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/player/PlayerGhost.cpp
)

# PUBLICLY including header file Application.h so it can be seen by Application.cpp and other files
target_include_directories(${MYSTERY_MAZE_GAME_TARGET_NAME} 
	 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#linking just the GameEngine which is already linked to the SFML libraries
target_link_libraries(${MYSTERY_MAZE_GAME_TARGET_NAME} PUBLIC ${MYSTERY_MAZE_ENGINE_TARGET_NAME})

#creati and define a function to copy libraries files 
function (CopyLibDirToTarget LIB_NAME TARGET_NAME)
#add new post build event command to copy sfml libraries to Debug/ dir
add_custom_command(TARGET ${TARGET_NAME}
	POST_BUILD 
	COMMAND 
	#evaluate and copy files if they changed. CMAKE_COMMAND is a command line saved somewhere on our PC
	${CMAKE_COMMAND} -E copy_directory
	#specify files to copy
	$<TARGET_FILE_DIR:${LIB_NAME}>
	#specify the directory to copy to later
	$<TARGET_FILE_DIR:${TARGET_NAME}>
)
endfunction()

#use function to copy directory with SFML files from GameEngine
CopyLibDirToTarget(${MYSTERY_MAZE_ENGINE_TARGET_NAME} ${MYSTERY_MAZE_GAME_TARGET_NAME})

#creating variables for assets for post build
set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

#coppy resources to the final build
add_custom_command(
	TARGET ${MYSTERY_MAZE_GAME_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	${RESOURCE_SOURCE_DIR}
	$<TARGET_FILE_DIR:${MYSTERY_MAZE_GAME_TARGET_NAME}>/${RESOURCE_FOLDER_NAME}
)

#include config file config.in
configure_file(
	#tell to make configuration:
	"config.h.in"
	#tell to put it where the game is in folder with a new name:
	"${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES
)


