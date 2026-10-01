cmake_minimum_required(VERSION 3.15)

project("threads hw2" VERSION 0.1.0 LANGUAGES CXX)

set(PROJECT_NAME
    main
)

set(SOURCES 
    task3.cpp
)
set(CMAKE_CXX_COMPILER g++-13)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -g -O1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=thread")

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 17)
