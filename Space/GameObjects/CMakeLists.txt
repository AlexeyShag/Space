cmake_minimum_required(VERSION 3.10.2)
project(GameObjects)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++1y -Wall" )
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

add_library(${PROJECT_NAME}_lib STATIC 
	GameObject.h 
	GameObject.cpp 
	UI/UI.h 
	UI/UI.cpp 
	UI/Button/Button.h 
	UI/Button/Button.cpp 
	UI/Text/Text.h 
	UI/Text/Text.cpp 
	UI/UIBox/UIBox.h 
	UI/UIBox/UIBox.cpp 
	Unit/Unit.h 
	Unit/Unit.cpp 
	Unit/Parts/Parts.h 
	Unit/Parts/Parts.cpp 
	Unit/SpaceShip/SpaceShip.h 
	Unit/SpaceShip/SpaceShip.cpp
)
