add_library(IOManagement STATIC opening_reading_closing.cpp find_next_event.cpp io_management.cpp)
target_include_directories(IOManagement PUBLIC ../include)

add_library(PaymentsManagement STATIC opening_reading_closing.cpp payments_management.cpp)
target_include_directories(PaymentsManagement PUBLIC ../include)

add_library(BookingsManagement STATIC opening_reading_closing.cpp find_next_event.cpp bookings_management.cpp)
target_include_directories(BookingsManagement PUBLIC ../include)

add_library(DateTime STATIC date_time.cpp)
target_include_directories(DateTime PUBLIC ../include)

add_library(Car STATIC car.cpp)
target_include_directories(Car PUBLIC ../include)

add_library(Parking STATIC parking.cpp)
target_include_directories(Parking PUBLIC ../include)

add_library(Booking STATIC booking.cpp)
target_include_directories(Booking PUBLIC ../include)
