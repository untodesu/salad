function(add_salad_example target)
    add_executable(${target} "${CMAKE_CURRENT_LIST_DIR}/${target}.c")
    target_link_libraries(${target} salad)
    if(NOT MSVC)
        target_link_libraries(${target} m)
    endif()
endfunction()

add_salad_example(sine)
