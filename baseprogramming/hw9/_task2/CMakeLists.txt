cmake_minimum_required(VERSION 3.22.1)

project(hw9 VERSION 0.1.0 LANGUAGES CXX)

set(PROJECT_NAME main)

set(HEADERS 
    figure.h 
    equilateralTriangle.h 
    isoscelesTriangle.h 
    parallelogram.h 
    quadangle.h
    rectangle.h
    rightTriangle.h
    rum.h
    square.h
    triangle.h
)

set(SOURCES 
    main.cpp 
    figure.cpp 
    equilateralTriangle.cpp 
    isoscelesTriangle.cpp 
    parallelogram.cpp
    quadangle.cpp
    rectangle.cpp
    rightTriangle.cpp
    rum.cpp
    square.cpp
    triangle.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_property(TARGET main PROPERTY CXX_STANDARD 14)