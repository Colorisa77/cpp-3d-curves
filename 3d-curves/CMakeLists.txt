cmake_minimum_required(VERSION 3.22)
project(curves_library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -O2")

set(CURVES_SOURCES
    circle.cpp
    ellipse.cpp
    helix.cpp
)

add_library(curves_library SHARED ${CURVES_SOURCES})

target_include_directories(curves_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
