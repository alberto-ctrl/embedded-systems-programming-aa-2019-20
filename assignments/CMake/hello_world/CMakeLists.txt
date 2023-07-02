cmake_minimum_required(VERSION 3.10.2)

project(hello_world
		DESCRIPTION "Our first cmake project"
		VERSION 0.1
		LANGUAGES CXX)

add_executable(hello hello_world.cpp)
