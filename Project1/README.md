# The Dining Philosophers Problem (C)
### Project made for the Operating Systems 2 course at college

## Description
The Dining Philosophers Problem is a classical synchronization problem that is often used to demonstrate the challanges in concurrent programming and the implementation of synchronization mechanisms to avoid issues such as deadlock and starvation of one of our philosophers. The problem consists of a certain number of philosophers sitting at the table. They need two forks to eat their meal. However, only one fork can eat without causing deadlock which is a state in which all philosophers are waiting indefinitely for each other. The other unwanted state is starvation that happens when some philosophers never get to eat.

## Problem Overview
Each philosopher can be in one of three states:
* Thinking: the philosopher is not using any resources.
* Hungry: the philosopher want to eat but is waiting for forks.
* Eating: the philosopher has picked up both forks and is eating.

## Running the program
To run the program, ensure that you have a C compiler like gcc and pthread library installed on your system.
### Steps to build and run
1. Clone the repository:
```
git clone https://github.com/3PointCode/OperatingSystems2_Project
```
2. Use the Makefile to compile the program using gcc:
```
make eating_philosophers
```
Or use this command:
```
gcc -o eating_philosophers eating_philosophers.c -lpthread
```
3. Run the program: after the compilation process, you can run the program with desired number of philosophers as an argument:
```
./eating_philosophers <number_of_philosophers>
```
Example:
```
./eating_philosophers 5
```
4. The program will display the state of each philosopher as they think, become hungry and eat. Each philosopher's activity is printed in the terminal.

## Implementation
This project simulates the **Dining Philosophers Problem** using **pthreads** for multithreading and synchronization. The program manages a set of philosophers who alternately think, become hungry and eat while sharing a set of forks. The goal is to avoid **deadlock** and **starvation**.
### Libraries Used
* **pthread.h**: 
    * A standard POSIX threads library used for creating and managing threads. Each philosopher is implemented as a separate thread, allowing them to perform actions concurrently.
    * Used functions:
        * pthread_create() - creates a new thread.
        * pthread_join() - waits for the thread to finish execution.
        * pthread_mutex_t - mutexes to ensure safe access to shared resources.
        * pthread_cont_t - condition variables used for managing the state of philosophers and allowing them to wait for forks.
* **stdlib.h**: 
    * Standard library that is used for memory allocation and other utility functions.
    * Used functions:
        * mallloc() - allocates memory for arrays of philosopher states, mutexes and condition variables.
        * atoi() - converts the command-line arguments to integers.
        * free() - frees dynamically allocated memory.
* **stdio.h**:
    * Standard input-output library.
    * Used functions:
        * printf()
* **unistd.h**:
    * Provides access to POSIX operating system API, including functions for sleeping, which is used to simulate philosophers thinking and eating for random periods of time.
    * Used funtions:
        * sleep() - pauses the execution of a philosopher's thread for a random period of time to simulate thinking and eating.
### Data Structures
* **state[]** - an integer array where each element represents the current state of a philosopher. Possible states are:
    * THINKING (0) - the philosopher is thinking. 
    * HUNRGY (1) - the philosopher is hungry.
    * EATING (2) - the philosopher is eating.
* **mutexes[]** - an array of mutexes where each philosopher has an associated mutex that ensures only one philosopher can access a fork at any given time.
* **conds[]** - an array of condition variables, each associated with a philosopher. When a philosopher is hungry but cannot eat, they wait on their respective condition variable until the forks become available.

## Problem breakdown
The Dining Philosophers Problem models a situation where a limited number of resources (forks) are shared by multiple processes (the philosophers).
The challenge is to desing a solution where philosophers can eat without causing deadlock or starvation.
* **Deadlock**: This can happen when all philosophers pick up one fork simultaneously and wait for the second fork, leading to a cycle of waiting.
* **Starvation**: This occurs if some philosophers are blocked from eating while others are able to proceed.

### Solution approach
1. **Mutexes**: to ensure mutual exclusion when accessing shared resources (forks), each fork is protected by a mutex. This ensures that only one philosopher can pick up a particular fork at any given time.
2. **Condition variables**: these are used to managed philosopher states efficiently. When a philosopher is hungry but can't pick up both forks, they will wait on the condition variable until they are allowed to proceed.

## Threads and what they represent
**Philosopher threads**: Each philosopher runs in its own thread. A philosopher can be in one of the following states:
* Thinking: the philosopher is not using any resources and is simply thinking.
* Hungry: the philosopher wants to eat but is waiting for the forks to become available.
* Eating: the philosopher has picked up both forks and is eating.

### Synchronization and critical sections
Critical sections refer to parts of the code that access shared resources (forks) and must be synchronized to prevent race conditions.
1. **Fork mutexes**: each fork is protected by a mutex, ensuring that no two philosophers can simultaneously use the same fork.
2. **Philosopher mutexes**: each philosopher's state is protected by a mutex to ensure that only one philosopher can modify their state at a time

### Critical sections
* **Fork Access**: A philosopher can only pick up forks if his left and right neighbours are not eating. This is ensured by the state of the neighbours before allowing a philosopher to proceed with eating.
* **Philosopher State**: The state of each philosopher is updated with a mutex and the program uses a condition variable to allow philosophers to wait when they are hungry and notify them when they can start eating.