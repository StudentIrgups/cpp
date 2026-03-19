cmake_minimum_required(VERSION 3.22.1)

project(hw11 VERSION 0.1.0 LANGUAGES CXX)

set(PROJECT_NAME
    main
)

set(HEADERS
    main.h
    extended_array.h
)

set(SOURCES 
    main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 17)
