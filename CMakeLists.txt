cmake_minimum_required(VERSION 3.0)
project(sge2)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)
set(SOURCES engine.cpp entity.cpp graphics.cpp inputevents.cpp main.cpp scriptengine.cpp)

include_directories(/usr/include/lua5.3)
add_executable(sge2 ${SOURCES})
target_link_libraries(sge2 lua5.3 SDL)

