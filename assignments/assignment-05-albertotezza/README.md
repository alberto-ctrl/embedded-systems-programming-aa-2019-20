# Assignment on Threads and Tasks

In this assignment you are required to implement a multithreaded version of a simplified grep program, i.e. a program that finds lines that match a certain string in a file.

You must start with the `main.cpp` included in your assignment:
1. create the `n` worker threads (the number is the third argument);
2. split the vector into n equal size regions, each thread look for instances of the string in a separate region;
3. be careful about the output: which is the problem? can you find a solution to improve it?


To compile the program:
`g++ -o main main.cpp -pthread`
to run the program (example):
`./main midsummer.txt summer 3`
  0          1          2    3
