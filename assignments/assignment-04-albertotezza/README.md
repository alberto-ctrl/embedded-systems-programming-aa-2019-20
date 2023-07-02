# Final assignment on C++ Classes
This is the final assignment about classes.

This exercise requires you to design and implement a `Library` class. 

The `Library` class should include a `struct` called `Transaction`.
The `Transaction` struct should include a `Book`, a `Patron`, and a `Date`.

The `Library` class should have __data members__ for:
1. vector of `Book`,
2. vector of `Patron`,
3. vector of `Transaction`.

and include __function members__ for:
1. add books to the library,
2. add patrons to the library,
3. check out books,
4. return a vector that contains the names of all `Patron`s that owe fees.

Whenever a user checks out a book, have the library make sure that both the user and the book are in the library. If they aren't, report  an error. If not, create a `Transaction`, and place it in the vector of `Transaction`s.

Feel free to use either your own classes for `Book`, a `Patron`, and a `Date` or the ones provided as solutions of the previous assignments.

If you have any question, just write on the forum of the course. 
