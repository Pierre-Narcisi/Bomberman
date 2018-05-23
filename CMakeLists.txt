cmake_minimum_required(VERSION 3.10)
project(irrlichtWrapper)

set(CMAKE_CXX_STANDARD 11)

include_directories(/lib/include/irrlicht/)
include_directories(libs/SmartEvent/srcs/Event)
include_directories(libs/SmartEvent/srcs/HdlCollector)
include_directories(libs/SmartEvent/srcs/Manager)

add_executable()
