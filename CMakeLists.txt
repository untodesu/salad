cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(SALAD LANGUAGES C VERSION 0.0.2)

option(SALAD_EXAMPLES "Build example applications" ON)
option(SALAD_PARANOID "Do additional checks when resolving functions" ON)

add_library(salad STATIC
    "${CMAKE_CURRENT_LIST_DIR}/include/AL/al.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/AL/alc.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/AL/efx.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/AL/salad.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/salad.c")
target_include_directories(salad PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
target_link_libraries(salad PUBLIC ${CMAKE_DL_LIBS})

if(SALAD_PARANOID)
    target_compile_definitions(salad PRIVATE SALAD_PARANOID)
endif()

if(SALAD_EXAMPLES)
    add_subdirectory(examples)
endif()
