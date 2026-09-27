cmake_minimum_required(VERSION 3.15)

project("threads hw1" VERSION 0.1.0 LANGUAGES CXX)

set(PROJECT_NAME
    main
)

set(SOURCES 
    task2.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 17)
