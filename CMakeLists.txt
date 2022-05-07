cmake_minimum_required(VERSION 3.23.0)

project(LR08 LANGUAGES C)

add_executable(${PROJECT_NAME} 
    src/main.c)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -fsanitize=address,undefined)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall -Wextra -Wpedantic
    -fsanitize=address,undefined)
