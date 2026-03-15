cmake_minimum_required(VERSION 3.31.6)

project(baseProgrammingProject VERSION 0.1.0 LANGUAGES CXX)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/mymenu
    ${CMAKE_CURRENT_SOURCE_DIR}/processor
    ${CMAKE_CURRENT_SOURCE_DIR}/vehicle
    ${CMAKE_CURRENT_SOURCE_DIR}/vehicle/air
    ${CMAKE_CURRENT_SOURCE_DIR}/vehicle/ground
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 

add_library(menu SHARED 
    mymenu/mymenu.h 
    mymenu/mymenu.cpp 
)

add_library(vehicles SHARED 
    vehicle/vehicle.h 
    vehicle/vehicle.cpp 
    vehicle/air/air.h 
    vehicle/air/air.cpp 
    vehicle/ground/ground.h 
    vehicle/ground/ground.cpp
)

add_library(processor SHARED 
    processor/processor.h
    processor/processor.cpp
)

add_executable(main main.cpp)

set_property(TARGET main PROPERTY CXX_STANDARD 14)

target_link_libraries(main menu vehicles processor)