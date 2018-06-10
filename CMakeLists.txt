cmake_minimum_required(VERSION 3.10)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)

include_directories(libs)
include_directories(libs/Json/includes)
include_directories(srcs)
include_directories(libs/irrKlang/includes)
include_directories(libs/irrlicht/includes)

add_executable(bomberman
        srcs/Constructors/BeingConsruct.hpp
        srcs/ECS/Component/Component.tpp
        srcs/ECS/Entity/Entity.cpp
        srcs/ECS/Entity/Entity.tpp
        srcs/ECS/Entity/Filter.tpp
        srcs/Game/Game.cpp
        srcs/Graphical/EventReceiver.cpp
        srcs/MapGen/mapGen.cpp
        srcs/Settings/Inputs.cpp
        srcs/Settings/Settings.cpp
        srcs/System/Being.cpp
        srcs/System/Ai.cpp
        srcs/System/Create.cpp
        srcs/System/Collider.cpp
        srcs/System/UpdateDeplacement.cpp
        srcs/Main.cpp)

target_link_libraries(bomberman ${CMAKE_CURRENT_LIST_DIR}/libs/irrlicht/libIrrlicht.so)
target_link_libraries(bomberman ${CMAKE_CURRENT_LIST_DIR}/libs/Json/libJson.so)
target_link_libraries(bomberman ${CMAKE_CURRENT_LIST_DIR}/libs/libIrrKlang.so)
