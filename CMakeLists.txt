cmake_minimum_required(VERSION 3.10)
project(Client)

set(CMAKE_CXX_STANDARD 17)

include_directories(libs/Json/srcs/Entity)
include_directories(libs/Json/srcs/Parser)
include_directories(libs/SmartEvent/includes)
include_directories(libs/SmartEvent/srcs)
include_directories(libs/SmartEvent/srcs/Event)
include_directories(libs/SmartEvent/srcs/HdlCollector)
include_directories(libs/SmartEvent/srcs/Manager)
include_directories(srcs)
include_directories(srcs/Component)
include_directories(srcs/ECS/Component)
include_directories(srcs/ECS/Entity)
include_directories(srcs/Graphical)
include_directories(tests)

add_executable(Client
        libs/Json/srcs/Entity/Entity.cpp
        libs/Json/srcs/Entity/JsonEntity.hpp
        libs/Json/srcs/Parser/Parser.cpp
        libs/Json/srcs/Parser/Parser.hpp
        libs/Json/tests/Entity/main.cpp
        libs/Json/tests/Parser/main.cpp
        libs/SmartEvent/srcs/Event/Event.cpp
        libs/SmartEvent/srcs/Event/Event.hpp
        libs/SmartEvent/srcs/Event/Event.tpp
        libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp
        libs/SmartEvent/srcs/HdlCollector/HdlCollector.hpp
        libs/SmartEvent/srcs/Manager/Manager.hpp
        libs/SmartEvent/srcs/Manager/Manager.tpp
        libs/SmartEvent/tests/Event/main.cpp
        libs/SmartEvent/tests/HdlCollector/main.cpp
        srcs/Component/BoxCollider.hpp
        srcs/Component/Position.hpp
        srcs/ECS/Component/Component.hpp
        srcs/ECS/Component/Component.tpp
        srcs/ECS/Entity/Entity.cpp
        srcs/ECS/Entity/Entity.hpp
        srcs/ECS/Entity/Entity.tpp
        srcs/ECS/Entity/EntityErrors.hpp
        srcs/ECS/Entity/Filter.hpp
        srcs/ECS/Entity/Filter.tpp
        srcs/Graphical/EventReceiver.cpp
        srcs/Graphical/EventReceiver.hpp
        srcs/Main.cpp
        tests/basicECS/Components.hpp
        tests/basicECS/Main.cpp
        tests/basicECS/Systems.hpp
        tests/graphicalTest/test.cpp srcs/Graphical/ComponentBeing.hpp srcs/Graphical/ComponentKeyboard.hpp srcs/Graphical/ComponentCamera.hpp srcs/Graphical/ComponentUnanimatedObject.hpp srcs/Graphical/ComponentController360.hpp srcs/Graphical/ComponentExplosion.hpp srcs/Graphical/SystemCreate.hpp srcs/Graphical/SystemCreateMap.cpp srcs/Graphical/SystemCreateWall.cpp srcs/Graphical/SystemCreateDeletableWall.cpp srcs/Graphical/SystemCreatePlayer.cpp srcs/Graphical/SystemUpdate.hpp srcs/Graphical/SystemUpdateDeplacement.cpp srcs/Graphical/SystemEvent.hpp srcs/Graphical/SystemEventManager.cpp)
