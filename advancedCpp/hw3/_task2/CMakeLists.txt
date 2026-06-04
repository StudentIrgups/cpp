cmake_minimum_required(VERSION 3.22.1)

project("advancedCpp hw3" VERSION 0.1.0 LANGUAGES CXX)

set(PROJECT_NAME
    main
)
set(HEADERS
    my_list.hpp
)
set(SOURCES 
    main.cpp
    my_list.cpp
)
find_package(Catch2 REQUIRED)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 17)
target_link_libraries(main PRIVATE Catch2::Catch2)
