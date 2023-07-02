cmake_minimum_required(VERSION 3.10)

# set the project name
project(classes_assignments)

add_compile_options(-Wall)

# add the executable
add_executable(main main.cpp Book.cpp Library.cpp Patron.cpp Date.cpp)

# add the test directory for tests
add_subdirectory(tests)