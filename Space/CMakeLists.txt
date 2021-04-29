cmake_minimum_required(VERSION 3.12)
project(Space)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17 -Wall" )
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(SOURCE_FILES src)

#set(SFML_STATIC_LIBRARIES TRUE)


execute_process(
	COMMAND bash "-c" "${PROJECT_SOURCE_DIR}/run.sh"
	COMMENT "all include have been coping"
)


set(SFML_libs ${SFML_SOURCE}/sfml-window ${SFML_SOURCE}/sfml-graphics )

include_directories(${PROJECT_SOURCE_DIR}/include)


if (${CMAKE_SYSTEM} MATCHES "Linux")
	message("Lunix")

	set(SFML_SOURCE ${PROJECT_SOURCE_DIR}/SFML_Linux/SFML/bin)
	include_directories(${PROJECT_SOURCE_DIR}/SFML_Linux/SFML/include)
	set(SFML_DIR ${PROJECT_SOURCE_DIR}/SFML_Linux/SFML/lib/cmake/SFML)
	find_package(SFML 2.5.1 COMPONENTS window graphics REQUIRED)
elseif (${CMAKE_SYSTEM} MATCHES "Darwin")
	message("MacOS")
	set(SFML_SOURCE ${PROJECT_SOURCE_DIR}/SFML_MacOS/SFML/lib)
	set(SFML_DIR ${PROJECT_SOURCE_DIR}/SFML_MacOS/SFML/lib/cmake/SFML)
	include_directories(${PROJECT_SOURCE_DIR}/SFML_MacOS/SFML/include)
	link_directories(${PROJECT_SOURCE_DIR}/SFML_MacOS/SFML/lib)
	link_directories(${PROJECT_SOURCE_DIR}/SFML_MacOS/SFML/Frameworks)
	find_package(SFML 2.5.1 COMPONENTS window graphics REQUIRED)
elseif (TRUE)
	message("ERROR")
endif ()


add_subdirectory(Game)
add_subdirectory(Graphics)
add_subdirectory(Geometry)
add_subdirectory(GameObjects)
add_subdirectory(Controllers)
add_subdirectory(Animation)
add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})


target_link_libraries(${PROJECT_NAME} PRIVATE Game_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE Graphics_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE Geometry_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE GameObjects_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE Controllers_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE Animation_lib)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window sfml-graphics)



if (FALSE)
endif()
