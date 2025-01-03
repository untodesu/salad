add_executable(mains "${CMAKE_CURRENT_LIST_DIR}/mains.c")
target_link_libraries(mains PRIVATE salad)

add_executable(sine "${CMAKE_CURRENT_LIST_DIR}/sine.c")
target_link_libraries(sine PRIVATE salad)

if(NOT MSVC)
    # Ensure every example target links with
    # the math library on all POSIX environments
    link_libraries(m)
endif()
