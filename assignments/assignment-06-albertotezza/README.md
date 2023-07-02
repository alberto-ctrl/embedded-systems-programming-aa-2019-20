# POSIX Condition Variables

In this assignment you are required to solve the following problems:

1. COUNTER
Two threads increment a counter. When the counter reaches a certain value, the state of a third thread must change its state from blocked to ready.

Fill in the missing instruction in file `counter.cpp` and avoid a busy waiting.

2. BANK
One thread deposits money on a bank account while two other threads withdraw. The withdrawer cannot get money when the balance is less than a certain amount. Fill in the missing instruction in file `bank.cpp` to avoid a busy waiting.

3. READERS and WRITERS
Create a readers/writers synchronization mechanism with mutexes and condition variables.
