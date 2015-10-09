cmake_minimum_required(VERSION 3.2)
project(pathtracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES filters/SimpleFilter.cpp filters/SimpleFilter.h exporters/PPMExporter.cpp exporters/PPMExporter.h core/Primitive.cpp core/Primitive.h core/Intersection.h core/Scene.cpp core/Scene.h core/Camera.cpp core/Camera.h shapes/Sphere.cpp shapes/Sphere.h)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(pathtracer ${SOURCE_FILES} main.cpp core/Geometry.cpp core/Film.h core/Film.cpp core/Filter.h core/Filter.cpp core/ImageExporter.h core/ImageExporter.cpp)