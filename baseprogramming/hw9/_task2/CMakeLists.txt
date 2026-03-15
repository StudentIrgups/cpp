cmake_minimum_required(VERSION 3.31.6)

project(hw9 VERSION 0.1.0 LANGUAGES CXX)

add_executable(main 
    main.cpp 
    figure.h 
    figure.cpp 
    equilateralTriangle.h 
    equilateralTriangle.cpp 
    isoscelesTriangle.h 
    isoscelesTriangle.cpp 
    parallelogram.h 
    parallelogram.cpp
    quadangle.h
    quadangle.cpp
    rectangle.h
    rectangle.cpp
    rightTriangle.h
    rightTriangle.cpp
    rum.h
    rum.cpp
    square.h
    square.cpp
    triangle.h
    triangle.cpp
)

set_property(TARGET main PROPERTY CXX_STANDARD 14)