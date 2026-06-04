cmake_minimum_required(VERSION 3.22.1)

project("advancedCpp project" VERSION 0.1.0 LANGUAGES CXX)

set(PROJECT_NAME
    main
)

set(HEADERS
    ini_parser.hpp
)

set(SOURCES 
    main.cpp
    ini_parser.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 17)
