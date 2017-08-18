cmake_minimum_required(VERSION 3.7)
project(filler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        includes/filler.h
        includes/get_next_line.h
        src/main.c
        src/reading.c
        src/second.c
        src/piece_serv.c
        src/int_map.c.c)

add_executable(filler ${SOURCE_FILES})
target_link_libraries(filler ${CMAKE_SOURCE_DIR}/libft/libft.a)