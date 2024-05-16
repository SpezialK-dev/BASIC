# TODO
Hier kommen projekte weite verbesserungs ideen rein, welche die codebase aufräumen sollen und schneller machen sollen

- [X] eine lib für oft gebrauchte funktionen schreiben sodas es einfacher ist code zu optimisen später
- [X] fix the problem that causes funk_var causes when being imported into another class
- [X] create a default constructor for funkt_var
- [X] rework all funktions to have a similar type, of getting 2 bvars as input and return a void pointer. because otherwiese we have a problem
- [X] Fix some copy stuff when creating a funk_var
- [ ] copying the name of the funk var should be smarter and and go out of the loop if a stop has been found 
- [x] isequal should be fixed properly (never had an issue but rather the calling was the issue)
- [ ] properly deal with garbage input
- [X] single char input acceptance
- [X] fix all Issues that valgrind finds 
    - [ ] fix all the memmory leaks created through fixing the issues()
- create a funktion to dealocate everything when closing the programm
- [ ] maybe clean up the code for LET
- [ ] add String methode should not be to hard
- [ ] Fix float conversion error
    they semi work now, but things starting with 0 just get cut of for no reason, also weird things happen with finding ending 
- [X] create a typedef for the funktions
- [ ] make funktions always return a variable, to prevent crashes on certain cpus. [Source](https://stackoverflow.com/questions/47899971/c-getting-error-illegal-instruction-core-dumped-upon-bitwise-or-operatio)
- [X] seperate the h files into their own folder and fix imports that problem that will happen because of that 
- [ ] create a copy construcor / follow the rule of 5
- [ ] 
