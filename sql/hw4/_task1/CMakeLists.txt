cmake_minimum_required(VERSION 3.15)
project(ClientManager CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PostgreSQL REQUIRED)
find_package(libpqxx CONFIG REQUIRED)

add_executable(client_manager task1.cpp clientManager.cpp)
target_include_directories(client_manager PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(client_manager PRIVATE
    libpqxx::pqxx
    PostgreSQL::PostgreSQL
)