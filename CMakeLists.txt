cmake_minimum_required(VERSION 3.2)
project(pathtracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES filters/SimpleFilter.cpp filters/SimpleFilter.h)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(pathtracer ${SOURCE_FILES} main.cpp core/geometry.cpp core/film.h core/film.cpp core/filter.h core/filter.cpp core/imageexporter.h core/imageexporter.cpp)