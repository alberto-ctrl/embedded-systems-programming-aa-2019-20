include_directories(..)

add_executable(testBook testBook.cpp ../Book.cpp ../Date.cpp)
add_executable(testDate testDate.cpp ../Date.cpp)
add_executable(testPatron testPatron.cpp ../Patron.cpp )