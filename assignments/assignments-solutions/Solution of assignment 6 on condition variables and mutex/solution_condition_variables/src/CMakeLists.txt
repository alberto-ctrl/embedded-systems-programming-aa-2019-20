add_executable(bank bank.cpp)
target_link_libraries(bank PRIVATE pthread)
add_executable(counter counter.cpp)
target_link_libraries(counter PRIVATE pthread)

add_executable(test_RW test_RW.cpp)
target_link_libraries(test_RW PRIVATE RW pthread)