cmake_minimum_required(VERSION 3.22.1)

project("algorithms hw7" VERSION 0.1.0 LANGUAGES CXX)

add_library(dfs STATIC
    dfs.h
    dfs.cpp
)

add_library(qu STATIC
    queue.h
    queue.cpp
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

target_link_libraries(main dfs qu)