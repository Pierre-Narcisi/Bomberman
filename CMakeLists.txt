cmake_minimum_required(VERSION 3.10)
project(Bomberman)

set(CMAKE_CXX_STANDARD 17)

include_directories(libs)
include_directories(libs/Json/srcs)
include_directories(libs/Json/srcs/Entity)
include_directories(libs/Json/srcs/Parser)
include_directories(libs/Json/tests/Parser/srcs/Entity)
include_directories(libs/Json/tests/Parser/srcs/Parser)
include_directories(libs/SmartEvent/srcs)
include_directories(libs/SmartEvent/srcs/Event)
include_directories(libs/SmartEvent/srcs/HdlCollector)
include_directories(libs/SmartEvent/srcs/Manager)
include_directories(srcs)
include_directories(srcs/Component)
include_directories(srcs/Console)
include_directories(srcs/ECS/Component)
include_directories(srcs/ECS/Entity)
include_directories(srcs/Game)
include_directories(srcs/Graphical)
include_directories(srcs/MapGen)
include_directories(srcs/Settings)
include_directories(srcs/System)
include_directories(srcs/Systems)
include_directories(tests/basicECS)

add_executable(Bomberman
        libs/Json/srcs/Entity/Entity.cpp
        libs/Json/srcs/Entity/Entity.hpp
        libs/Json/srcs/Parser/Parser.cpp
        libs/Json/srcs/Parser/Parser.hpp
        libs/SmartEvent/srcs/Event/Event.cpp
        libs/SmartEvent/srcs/Event/Event.hpp
        libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp
        libs/SmartEvent/srcs/HdlCollector/HdlCollector.hpp
        libs/SmartEvent/srcs/Manager/Manager.hpp
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
        srcs/Console/Console.cpp
        srcs/Console/Console.hpp
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
        srcs/System/Create.cpp
        srcs/System/Create.hpp
        srcs/System/Destroyer.hpp
        srcs/System/Event.hpp
        srcs/System/EventManager.cpp
        srcs/System/Explode.hpp
        srcs/System/Update.hpp
        srcs/System/UpdateDeplacement.cpp
        tests/basicECS/Components.hpp
        tests/basicECS/Systems.hpp
        tests/graphicalTest/test.cpp srcs/Constructors/BeingConsruct.hpp srcs/Constructors/Destructors.hpp)

target_link_libraries(Bomberman /usr/lib/x86_64-linux-gnu/libIrrlicht.so)
target_link_libraries(Bomberman /usr/lib/x86_64-linux-gnu/libGL.so)
target_link_libraries(Bomberman ${CMAKE_CURRENT_LIST_DIR}/libs/Json/libJson.so)
target_link_libraries(Bomberman /usr/lib/x86_64-linux-gnu/libpthread.so)
