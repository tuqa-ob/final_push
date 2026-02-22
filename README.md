*This activity has been created as part of the 42 curriculum by ualabede tobaidat*

# PUSH_SWAP

## Description

Push_swap is an algorithmic project from the
42 Network curriculum.

The objective is to sort a list of integers using two stacks (A and B) and a limited set of operations. The challenge is not only to sort the numbers correctly, but to do so using the minimum number of operations.

This project focuses on:

- Algorithm design
- Time complexity analysis
- Stack data structures
- Linked lists
- Bitwise operations
- Memory management in C

## Instructions

make        # compile the program
make clean  # remove object files
make fclean # remove object files and executable
make re     # recompile everything

Run the program:
./push_swap 4 67 3 87 23

The program outputs the list of operations needed to sort the numbers

* Algorithm Strategy
--simple Forces the use of your O(n^2) algorithm. (selection sort)
--medium Forces the use of your O(n√n) algorithm. (chunk-based)
--complex Forces the use of your O(n log n) algorithm. (radix sort LSD)
--adaptive Forces the use of your adaptive algorithm based on disorder. This is
the default behavior if no selector is given.


Normalization step: convert values to indexed ranks before sorting

* Allowed Operations

sa / sb / ss
pa / pb
ra / rb / rr
rra / rrb / rrr

* Error Handling

- Duplicate numbers
- Invalid arguments
- Integer overflow
- Memory leaks
On error, the program prints:
Error

## Resources

- Man pages for C standard functions

- 42 project subject PDF

- Peer evaluations

- AI for debugging and algorithm explanation
