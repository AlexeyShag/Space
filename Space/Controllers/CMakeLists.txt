cmake_minimum_required(VERSION 3.10.2)
project(Controllers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++1y -Wall" )
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

add_library(${PROJECT_NAME}_lib STATIC ActionController/ActionController.h ActionController/ActionController.cpp EventController/EventController.h EventController/EventController.cpp Action/Action.h Action/Action.cpp AnimationController/AnimationController.h AnimationController/AnimationController.cpp ImageController/ImageController.h ImageController/ImageController.cpp GameController/GameController.h GameController/GameController.cpp GameController/PlayerController/PlayerController.h GameController/PlayerController/PlayerController.cpp)
