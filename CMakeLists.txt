cmake_minimum_required(VERSION 3.0)
project(sge2)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)
set(SOURCES src/engine.cpp src/entity.cpp src/graphics.cpp src/inputevents.cpp src/main.cpp src/scriptengine.cpp src/graphicsadapter.hpp src/inputadapter.hpp src/sfml.cpp src/sfml.hpp)

include_directories(/usr/include/lua5.3)
add_executable(sge2 ${SOURCES})
target_link_libraries(sge2 lua5.3 sfml-graphics sfml-window sfml-system)

