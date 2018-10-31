# todo

## A task planner which works on the shoulders of arrays and fstream.

### Usage

First of all download the source code using zip archive or

`git clone https://github.com/gurungrahul2/todo.git`

Then compile the `todo.cpp` file using your favourite IDE, or compiler.

This program currently offers three options, which are to `add`, `delete` tasks and last one to `exit` the program.

### Program Outline

This is a simple to-do tasks planner in which user can add his/her daily todo tasks and delete them after completing them. This program is fully wrote in C++ and is completely terminal based. We use arrays to store our data and then save our data in a `txt` file, to inject old data when user opens the program next day.

#### Array
We used arrays as our data structure to save our elements to the `txt` file. We have used array deletion for the deletion of tasks.

#### File Handling
File Handling is used to save our variable before successfully closing the exam. We did this to import our variable when program is opened in the future. Every time the program runs it automatically detects the file and imports the variables and you can direcly edit the `tasks.txt` file to change variable too.

### Working & Algorithm
This program is actually a infinite loop which asks user to `add`, `delete` or `exit`. This `exit` is the only way to stop the loop and close the program. Further if-else loops are used to further add logic for three options.
