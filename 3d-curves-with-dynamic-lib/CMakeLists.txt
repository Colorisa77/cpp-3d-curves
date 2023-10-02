cmake_minimum_required(VERSION 3.22)

project(main_app CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(main_app main.cpp)

set(LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")

    set(CURVES_LIBRARY ${LIBRARY_DIR}/Debug/libcurves_library.so)
else()
    set(CURVES_LIBRARY ${LIBRARY_DIR}/Release/libcurves_library.so)
endif()

target_link_libraries(main_app ${CURVES_LIBRARY})

target_include_directories(main_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)