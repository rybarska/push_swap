push_swap is a 42 school project written in C that aims to sort stacks of integers using a limited set of operations. 
The project involves implementing an efficient sorting algorithm and optimizing it to minimize the number of operations performed.

Overview

push_swap takes as input two stacks, labeled A and B, each containing a random set of integers. 
The goal is to sort stack A in ascending order using the following operations:

* sa: Swap the first two elements of stack A.
* sb: Swap the first two elements of stack B.
* ss: Swap the first two elements of both stack A and stack B simultaneously.
* pa: Push the first element of stack B onto stack A.
* pb: Push the first element of stack A onto stack B.
* ra: Rotate stack A upwards, shifting all elements by one position.
* rb: Rotate stack B upwards, shifting all elements by one position.
* rr: Rotate both stack A and stack B upwards simultaneously.
* rra: Rotate stack A downwards, shifting all elements by one position.
* rrb: Rotate stack B downwards, shifting all elements by one position.
* rrr: Rotate both stack A and stack B downwards simultaneously.

Functionality: 

Key features of push_swap include:

* Sorting algorithm: Implementation of an efficient sorting algorithm that minimizes the number of operations required to sort the stack.
* Optimization: Optimization techniques to reduce the number of operations performed, resulting in faster sorting times.
* Error handling: Robust error handling to detect and handle various error conditions, such as invalid input or memory allocation failures.

Usage

Compile with make

Execute the program with a list of integers, like this: 

input: ./push_swap <list_of_integers>

Examples

$> ./push_swap 4 67 2 8 13

This command will sort the integers 4, 67, 2, 8, and 13 using the push_swap algorithm.
