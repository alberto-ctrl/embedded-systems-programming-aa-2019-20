cmake_minimum_required(VERSION 3.10.2)

project(shared_library_test
		DESCRIPTION "Test the creation of a shared library"
		VERSION 0.1
		LANGUAGES CXX)

#Generate the shared library from the sources
add_library(student SHARED lib/Student.cpp)

#Bring the headers, such as Student.h into the project
target_include_directories(student PUBLIC include)
