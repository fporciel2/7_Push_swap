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
The algorithm has a linear space complexity of O(n) and always uses an amount of memory regions equal to the input size. No memory expansion is required after the stack's creation.
The idea from the "Turk Algorithm" is to implement an adaptive algorithm based on a uniform cost model that performs a cost evaluation to choose the right sequence of operations based on the input size and the grade of order of the stack.
The main consequence of this approach is that this program cannot properly be considered the implementation of a sorting algorithm, but, in accordance with the data structure used, it must be considered the abstract implementation of an hardware scheduler, or an abstract algorithm generator: it generates and executes the algorithm based on the input size and order, trying to maintain a logarithimc time complexity ( O(n log n) ) for every input.
It is important to note that the effective time and space complexity of the program is many times greater than the complexity of the algorithm printed by the prgram in the push_swap language, but the latter is hopefully exactly what is effecitvely required in terms of modifications and comparisons.
For more informations, see directly the comments in the source files.

## Installation

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

### Checker
