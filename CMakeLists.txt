cmake_minimum_required(VERSION 3.7.2)
project(vrudakov.filler)

set(CMAKE_C_FLAGS "-std=c99")

set(SOURCE_FILES
        src/second.c
        src/main.c
        src/get_next_line.c
        libft/ft_atoi.c
        includes/filler.h
        libft/libft.h
        src/reading.c)

add_executable(vrudakov.filler ${SOURCE_FILES})
target_link_libraries(vrudakov.filler ${CMAKE_SOURCE_DIR}/libft/libft.a)