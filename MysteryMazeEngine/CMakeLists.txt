#using variable we created or was created for us in main CMakeLists.txt file
#this CMake list determines which source file will be used for the project
#caution - reference current directory path /src/main.cpp, or it will output an error

#Statically include library
add_library(${MYSTERY_MAZE_ENGINE_TARGET_NAME} STATIC
	#${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	#tells to include other project files in src/framework/ (.cpp files) and include/framework (header .h files)
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/World.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Actor.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Object.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Object.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/AssetManager.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/AssetManager.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/MathUtility.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/MathUtility.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Core.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.cpp

	#includes EntryPoint files to handle main
	${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
)

# PUBLICLY including header file Application.h so it can be seen by Application.cpp and other files
target_include_directories(${MYSTERY_MAZE_ENGINE_TARGET_NAME} 
	 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#linking SFML library after fetching  so the target will know dependent sfml libraries
target_link_libraries(${MYSTERY_MAZE_ENGINE_TARGET_NAME} 
	PUBLIC sfml-graphics 
	PUBLIC sfml-window 
	PUBLIC sfml-system 
	PUBLIC sfml-audio 
)

#creati and define a function to copy libraries files 
function (CopyLibToTarget LIB_NAME TARGET_NAME)
#add new post build event command to copy sfml libraries to Debug/ dir
add_custom_command(TARGET ${TARGET_NAME}
	POST_BUILD 
	COMMAND 
	#evaluate and copy files if they changed. CMAKE_COMMAND is a command line saved somewhere on our PC
	${CMAKE_COMMAND} -E copy_if_different
	#specify files to copy
	$<TARGET_FILE:${LIB_NAME}>
	#specify the directory to copy to later
	$<TARGET_FILE_DIR:${TARGET_NAME}>
)
endfunction()

#use function for each file
CopyLibToTarget(sfml-graphics ${MYSTERY_MAZE_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio ${MYSTERY_MAZE_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system ${MYSTERY_MAZE_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-window ${MYSTERY_MAZE_ENGINE_TARGET_NAME})
 
