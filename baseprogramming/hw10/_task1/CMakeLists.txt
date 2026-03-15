cmake_minimum_required(VERSION 3.31.6)

project(hw9 VERSION 0.1.0 LANGUAGES CXX)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/greeter
)

add_library(greeter STATIC
    greeter/greeter.h
    greeter/greeter.cpp
)

add_executable(main main.cpp)

set_property(TARGET main PROPERTY CXX_STANDARD 14)

target_link_libraries(main greeter)