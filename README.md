# push_swap - Stack Sorting

**push_swap** is a project in **C** that implements a sorting algorithm for numbers using two stacks. The main objective is to sort a series of numbers in stack A, using allowed operations on the stacks and minimizing the number of moves.

## Objective

The goal of the project is to implement a program that sorts numbers from a stack using a minimal number of instructions. The program should be able to sort a series of integers in stack A, using a second stack B as auxiliary.

## Allowed Operations

The program can use the following operations:

- `sa`: Swaps the first two elements of stack A.
- `sb`: Swaps the first two elements of stack B.
- `ss`: Performs `sa` and `sb` simultaneously.
- `pa`: Takes the first element of stack B and puts it into stack A.
- `pb`: Takes the first element of stack A and puts it into stack B.
- `ra`: Moves all elements of stack A one position up.
- `rb`: Moves all elements of stack B one position up.
- `rr`: Performs `ra` and `rb` simultaneously.
- `rra`: Moves all elements of stack A one position down.
- `rrb`: Moves all elements of stack B one position down.
- `rrr`: Performs `rra` and `rrb` simultaneously.

## Compilation

To compile the project, run the `make` command in the root directory:

```bash
make
```

## Execution

```bash
./push_swap <numbers>
```
