# Philosophers' Dining Problem (C)
### Project made for the Operating Systems 2 course at college

## Description
The Dining Philosophers Problem is a classical synchronization problem that is often used to demonstrate the challanges in concurrent programming and the implementation of synchronization mechanisms to avoid issues such as deadlock and starvation of one of our philosophers. The problem consists of a certain number of philosophers sitting at the table. They need two forks to eat their meal. However, only one fork can eat without causing deadlock which is a state in which all philosophers are waiting indefinitely for each other. The other unwanted state is starvation that happens when some philosophers never get to eat.

## Problem Overview
Each philosopher can be in one of three states:
* Thinking: the philosopher is not using any resources.
* Hungry: the philosopher want to eat but is waiting for forks.
* Eating: the philosopher has picked up both forks and is eating.

## Implementation

