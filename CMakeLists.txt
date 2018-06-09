cmake_minimum_required(VERSION 3.10)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)

include_directories(libs)
include_directories(libs/Json/includes)
include_directories(libs/Json/srcs/Entity)
include_directories(libs/Json/srcs/Parser)
include_directories(libs/Json/tests/Parser/srcs/Entity)
include_directories(libs/Json/tests/Parser/srcs/Parser)
include_directories(srcs)
include_directories(irrKlang)

add_executable(bomberman
        srcs/Component/AttributeBomb.hpp
        srcs/Component/Basics.hpp
        srcs/Component/Being.hpp
        srcs/Component/BoxCollider.hpp
        srcs/Component/Camera.hpp
        srcs/Component/Controller360.hpp
        srcs/Component/Graphicals.hpp
        srcs/Component/Keyboard.hpp
        srcs/Component/Stat.hpp
        srcs/Component/UnanimatedObject.hpp
        srcs/ECS/Component/Component.hpp
        srcs/ECS/Component/Component.tpp
        srcs/ECS/Entity/Entity.cpp
        srcs/ECS/Entity/Entity.hpp
        srcs/ECS/Entity/Entity.tpp
        srcs/ECS/Entity/EntityErrors.hpp
        srcs/ECS/Entity/Filter.hpp
        srcs/ECS/Entity/Filter.tpp
        srcs/Game/Game.cpp
        srcs/Game/Game.hpp
        srcs/Game/Score.hpp
        srcs/Game/Settings.hpp
        srcs/Graphical/EventReceiver.cpp
        srcs/Graphical/EventReceiver.hpp
        srcs/MapGen/mapGen.cpp
        srcs/MapGen/mapGen.hpp
        srcs/Settings/Inputs.cpp
        srcs/Settings/Inputs.hpp
        srcs/Settings/Settings.cpp
        srcs/Settings/Settings.hpp
        srcs/System/Being.cpp
        srcs/System/Being.hpp
        srcs/System/Ai.cpp
        srcs/System/Ai.hpp
        srcs/System/Create.cpp
        srcs/System/Create.hpp
        srcs/System/Destroyer.hpp
        srcs/System/Event.hpp
        srcs/System/EventManager.cpp
        srcs/System/Collider.cpp
        srcs/System/Collider.hpp
        srcs/System/Explode.hpp
				srcs/System/Graphical.hpp
        srcs/System/Update.hpp
        srcs/System/UpdateDeplacement.cpp
        srcs/Main.cpp)

target_link_libraries(bomberman /usr/lib/x86_64-linux-gnu/libIrrlicht.so)
target_link_libraries(bomberman ${CMAKE_CURRENT_LIST_DIR}/libs/Json/libJson.so)
target_link_libraries(bomberman /usr/lib/x86_64-linux-gnu/libpthread.so)
target_link_libraries(bomberman ${CMAKE_CURRENT_LIST_DIR}/irrKlang/bin/linux-gcc-64/libIrrKlang.so)
