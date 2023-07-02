add_executable(reading_from_file reading_from_file.cpp)

add_executable(test_currently_parked test_currently_parked.cpp)
target_link_libraries(test_currently_parked PRIVATE IOManagement PaymentsManagement DateTime Car Parking pthread)

add_executable(test_limits test_limits.cpp)

add_executable(test_parking_spaces test_parking_spaces.cpp)
target_link_libraries(test_parking_spaces PRIVATE IOManagement PaymentsManagement BookingsManagement DateTime Car Parking Booking pthread)