cmake_minimum_required(VERSION 3.15)
project(bookstore CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Boost 1.83 в /opt ---
set(BOOST_ROOT            "/opt/boost-1.83")
set(Boost_ROOT            "/opt/boost-1.83")
set(BOOST_INCLUDEDIR      "/opt/boost-1.83/include")
set(Boost_INCLUDE_DIR     "/opt/boost-1.83/include")
set(BOOST_LIBRARYDIR      "/opt/boost-1.83/lib")
set(Boost_LIBRARY_DIR     "/opt/boost-1.83/lib")
set(Boost_NO_SYSTEM_PATHS ON)

list(APPEND CMAKE_PREFIX_PATH "/usr/local" "/opt/boost-1.83")
set(CMAKE_POLICY_DEFAULT_CMP0144 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0167 NEW)

# --- PostgreSQL ---
find_package(PostgreSQL REQUIRED)

# --- Wt: ищем .so вручную в /usr/local/lib ---
find_library(WT_LIB            NAMES wt
             PATHS /usr/local/lib NO_DEFAULT_PATH)
find_library(WTDBO_LIB         NAMES wtdbo
             PATHS /usr/local/lib NO_DEFAULT_PATH)
find_library(WTDBOPOSTGRES_LIB NAMES wtdbopostgres
             PATHS /usr/local/lib NO_DEFAULT_PATH)

if(NOT WT_LIB OR NOT WTDBO_LIB OR NOT WTDBOPOSTGRES_LIB)
    message(FATAL_ERROR "Wt / Wt::Dbo not found in /usr/local/lib")
endif()

message(STATUS "WT_LIB        = ${WT_LIB}")
message(STATUS "WTDBO_LIB     = ${WTDBO_LIB}")
message(STATUS "WTDBOPOSTGRES = ${WTDBOPOSTGRES_LIB}")

find_path(WT_INCLUDE_DIR NAMES Wt/Dbo/Dbo.h
          PATHS /usr/local/include NO_DEFAULT_PATH)

if(NOT WT_INCLUDE_DIR)
    message(FATAL_ERROR "Wt headers not found in /usr/local/include")
endif()

message(STATUS "WT_INCLUDE_DIR = ${WT_INCLUDE_DIR}")

add_executable(bookstore task1.cpp)

target_include_directories(bookstore PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${WT_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    ${PostgreSQL_INCLUDE_DIRS}
)

target_link_libraries(bookstore PRIVATE
    ${WTDBOPOSTGRES_LIB}
    ${WTDBO_LIB}
    ${WT_LIB}
    ${PostgreSQL_LIBRARIES}
    pthread
)

set_target_properties(bookstore PROPERTIES
    BUILD_RPATH   "/usr/local/lib:/opt/boost-1.83/lib"
    INSTALL_RPATH "/usr/local/lib:/opt/boost-1.83/lib"
)