add_executable(maine main.cpp)
target_link_libraries(maine PRIVATE IOManagement PaymentsManagement BookingsManagement DateTime Car Parking Booking pthread)