cmake_minimum_required(VERSION 3.22.1)

project(hw9 VERSION 0.1.0 LANGUAGES CXX)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/leaver
)

add_library(leaver SHARED
    leaver/leaver.h
    leaver/leaver.cpp
)

add_executable(main main.cpp)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set_property(TARGET main PROPERTY CXX_STANDARD 14)

target_link_libraries(main leaver)