# 7_Push_swap
Push_swap is a versatile sorting algorithm visualization tool. Designed as part of a programming challenge, it demonstrates the efficiency of different sorting algorithms by visually displaying their operations.

## Table of Contents
- [Introduction](https://github.com/fporciel2/7_Push_swap/blob/main/README.md#introduction)
- [Description](https://github.com/fporciel2/7_Push_swap/blob/main/README.md#description)
  - [Language](https://github.com/fporciel2/7_Push_swap/blob/main/README.md#language)
  - [Algorithm](https://github.com/fporciel2/7_Push_swap/blob/main/README.md#algorithm)
- [Installation](https://github.com/fporciel2/7_Push_swap/blob/main/README.md#installation)
- [Usage](https://github.com/fporciel2/7_Push_swap/blob/main/README.md#usage)
  - [Push_swap](https://github.com/fporciel2/7_Push_swap/blob/main/README.md#push_swap)
  - [Checker](https://github.com/fporciel2/7_Push_swap/blob/main/README.md#checker)

## Introduction

The Push_swap and Checker programs are designed to work together for sorting integers using a set of specific instructions while visualizing the sorting process. Push_swap generates a sequence of instructions to sort a list of numbers, and Checker verifies whether these instructions are valid and successfully sort the list.

## Description

The Push_swap program sorts a random given list of integer numbers whose values must be between –2147483648 and 2147483647, i.e. it only accepts as input a list of 32-bit integer data type. It sorts, hypotetically, any random amount of numbers, but machine- and system-related limit are hopefully respected during the compilation process and inevitably imposed during execution.

The program treats the input list as an abstraction of a **hardware stack**, implemented as a **linked list**, and uses another similar structure in order to perform operations on the first one. So, the stack derived by input is called "stack A", and the auxiliar one is called "stack B".

### Language

In order to effectively sort the stack, the Push_swap program use a language configured as a set of operations. These operations are the only allowed to modify the stacks and they are the below-mentioned:

  * sa: swap a - swap the first 2 elements at the top of stack A
  * sb: swap b - swap the first 2 elements at the top of stack B
  * ss: sa and sb at the same time
  * pa: push a - take the first element at the top of stack B and put it at the top of stack A
  * pb: push b (basically the **pop** operation)- take the first element at the top of stack A and put it at the top of stack B
  * ra: rotate a - shift up all elements of stack A by 1
  * rb: rotate b - shift up all elements of stack B by 1
  * rr: ra and rb at the same time
  * rra: reverse rotate a - shift down all elements of stack A by 1
  * rrb: reverse rotate b - shift down all elements of stack B by 1
  * rrr: rra and rrb at the same time

### Algorithm

The algorithm used to sort the stack is freely inspired by the "Turk Algorithm", invented by [byaliego](https://github.com/byaliego) and enhanced by [beatrizdile](https://github.com/beatrizdile). (See also [this article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)).
The algorithm has a linear space complexity of O(n) and always uses an amount of memory regions equal to the input size. No memory expansion is required after the stack's creation: if the stack B grows, the stack A decreases accordingly, and viceversa.
The idea from the "Turk Algorithm" is to implement an adaptive algorithm based on a uniform cost model that performs a cost evaluation to choose the right sequence of operations based on the input size and the grade of order of the stack.
In this program, I try to build an implementation of the [introsort](https://en.wikipedia.org/wiki/Introsort) algorithm. For more informations, see directly the comments in the source files.

## Installation

Before you begin, please ensure you have the latest versions of **gcc** C compiler and **gnu make** installed on your system.

To download the program:

```
git clone git@github.com:fporciel2/7_Push_swap.git
```

To build the Push_swap program: 

```
make
```

To build the Checker program:

```
make bonus
```

## Usage

### Push_swap

Push_swap is the program responsible for generating a sequence of instructions to sort a list of numbers.

To use Push_swap, run the following command, passing the list of numbers as arguments:

```
./push_swap <list_of_numbers>
```
For example:

```
./push_swap 4 2 8 5 1
```
Push_swap will output a series of instructions in the standard output, which you can use to sort the input list.

### Checker

Checker is the program used to verify if a given sequence of instructions correctly sorts the list.

To use Checker, you need to pipe the output from Push_swap into Checker:

```
./push_swap <list_of_numbers> | ./checker <list_of_numbers>
```

For example:

```
./push_swap 4 2 8 5 1 | ./checker 4 2 8 5 1
```

Checker will then display "OK" if the instructions successfully sort the list, or "KO" if not.
