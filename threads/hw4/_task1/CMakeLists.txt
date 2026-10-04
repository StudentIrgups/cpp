cmake_minimum_required(VERSION 3.15)

project("threads" VERSION 0.1.0 LANGUAGES CXX)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -g -O1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=thread")

# --- Сервер ---
add_executable(server
    server.cpp
    server.h
    task1_serv.cpp
)

# --- Клиент ---
add_executable(client
    client.cpp
    client.h
    task1_cli.cpp
)

