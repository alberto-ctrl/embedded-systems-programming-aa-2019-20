# Make an automatic library - will be static or dynamic based on user setting
add_library(student SHARED Student.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(student PUBLIC ../include)

