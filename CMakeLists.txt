cmake_minimum_required(VERSION 3.10)
project(salad LANGUAGES C VERSION 0.0.1)

option(SALAD_PARANOID "Paranoid function retreiving" ON)
option(SALAD_EXAMPLES "Build examples" ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(salad STATIC
    "${CMAKE_CURRENT_LIST_DIR}/include/AL/al.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/AL/alc.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/AL/salad.h"
    "${CMAKE_CURRENT_LIST_DIR}/salad.c")
target_include_directories(salad PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

if(SALAD_PARANOID)
    message("-- SALAD_PARANOID = 1")
    target_compile_definitions(salad PRIVATE SALAD_PARANOID)
endif()

if(UNIX AND NOT APPLE)
    # Other POSIXes require libdl
    target_link_libraries(salad PUBLIC dl)
endif()

if(SALAD_EXAMPLES)
    message("-- Building SALAD examples")
    function(add_salad_example target)
        add_executable(${target} "${CMAKE_CURRENT_LIST_DIR}/examples/${target}.c")
        target_link_libraries(${target} salad)
    endfunction()
    add_salad_example(sine)
endif()
