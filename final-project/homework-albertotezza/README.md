// README.md
// Homework Inverno 2019 by Alberto Tezza


Code to simulate the managing of two parkings of an airport.

In "homework-albertotezza/source/main.cpp" you can change the capacity of two parkings:
    Parking P1{"PARK1", 200};
    Parking P2{"PARK2", 100};
The second argument of this variables represents the maximum capacity of parking.
You can change the values to simulate parkings of different capacities.


To COMPILE the code, set terminal path to "homework-albertotezza/build" and play this commands:
    cmake ..
    make

After in the same path compiling RUN with:
    ./source/maine


To ensure proper operation, make sure there are in the position "homework-albertotezza/input_files" the following files:
    -parcheggioUnoIngresso.txt
    -parcheggioUnoUscita.txt
    -parcheggioDueIngresso.txt
    -parcheggioDueUscita.txt
    -prenotazioni.txt



// TESTS: (terminal path: "homework-albertotezza/build")


- If you want to test only the reading from file, after compiling run with:
    ./tests/reading_from_file
(This read and show the data from "homework-albertotezza/input_files/input_example.txt")


- If you want to test the limits of an integer/float variable type (used by me to check the conversion of date and time don't reach overflow), after compiling run with:
    ./tests/test_limits


- If you want to run a test to see the car corretly parked in the parkings, after compiling run with:
    ./tests/test_currently_parked
Note: you can change the values to simulate parkings of different capacities modifying "homework-albertotezza/tests/test_currently_parked.cpp"


- If you want to run a test to see the actual capacities of the parking, after compiling run with:
    ./tests/test_parking_spaces
Notes:
 1) you can change the values to simulate parkings of different capacities modifying "homework-albertotezza/tests/test_parking_spaces.cpp"
 2) bookings management is designed only for one parking because the assignment don't specific completly the topic. So the decision to manage reservations for parking P1 only (in order to simplify the problem).
 The test show places currently reserved in a parking, so for Parking P2 this value is always zero
