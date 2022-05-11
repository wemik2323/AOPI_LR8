cmake_minimum_required(VERSION 3.23.0)

project(CURSE LANGUAGES C)

add_executable(${PROJECT_NAME} 
    src/main.c
    src/funcs.c)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -fsanitize=address,undefined -lm)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Werror
    -Wall -Wextra -Wpedantic -Wconversion
    -fsanitize=address,undefined)
