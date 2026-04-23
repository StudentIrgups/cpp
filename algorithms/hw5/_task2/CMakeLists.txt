cmake_minimum_required(VERSION 3.22.1)

project("algorithms hw5" VERSION 0.1.0 LANGUAGES CXX)

add_library(heapWalk SHARED 
    heapWalk.h
    heapWalk.cpp
)

set(PROJECT_NAME
    main
)

set(HEADERS
    main.h
)

set(SOURCES 
    main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 17)

target_link_libraries(main heapWalk)