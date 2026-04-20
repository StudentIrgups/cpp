cmake_minimum_required(VERSION 3.22.1)

project("algorithms hw3" VERSION 0.1.0 LANGUAGES CXX)

set(PROJECT_NAME
    main
)

set(SOURCES 
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 17)
