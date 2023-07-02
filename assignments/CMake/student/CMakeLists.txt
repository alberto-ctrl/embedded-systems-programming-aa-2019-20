cmake_minimum_required(VERSION 3.10.2)

project(directory_test
		DESCRIPTION "Show some distribution of files"
		VERSION 0.1
		LANGUAGES CXX)

		
add_executable(testStudent src/main.cpp src/Student.cpp)

# Bring the headers, such as Student.h into the project
target_include_directories(testStudent PUBLIC include)

