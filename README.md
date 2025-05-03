# MultithreadedSortingApplication
This C program sorts a list of integers using multiple threads. It splits the list into two halves, sorts each half in parallel using separate threads, and then merges the sorted halves using a third thread.

## Features

* **Multithreading**: Uses threads for sorting and merging the list.
* **User Input**: List size and elements are taken from the user.
* **Sorting Algorithm**: Bubble Sort is used to sort the list.

## Structure

1. **original\_list**: The input list provided by the user.
2. **sorted\_list**: The final sorted list after merging.
3. **sort\_thread**: Threads for sorting each half of the list.
4. **merge\_thread**: A thread for merging the sorted halves.
5. **pthread**: Used for thread management.

## How to Run

1. Compile the program with `pthread` support.
2. The user is prompted to input the list size and elements.
3. The program creates threads to sort each half of the list and then merges the sorted halves.
4. The sorted list is printed to the console.


## Requirements:

* C compiler (e.g., GCC)
* pthread library for thread management

## Notes:

This project demonstrates **multithreading** in C by using threads to concurrently sort and merge list halves. It uses **Bubble Sort**, but other algorithms can easily be substituted.

