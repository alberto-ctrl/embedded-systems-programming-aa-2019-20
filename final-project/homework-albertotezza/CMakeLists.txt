# Works with 3.10.2
cmake_minimum_required(VERSION 3.10.2)

# Project name and a few useful settings.
# Other commands can pick up the results
project (Homework
        VERSION 0.1
        DESCRIPTION "Homework Winter 2019"
        LANGUAGES CXX)

add_compile_options(-Wall -Wextra -pedantic -Werror)

# The compiled library code is here
add_subdirectory(library)

# The executable source code is here
add_subdirectory(source)

# The test code is here
add_subdirectory(tests)