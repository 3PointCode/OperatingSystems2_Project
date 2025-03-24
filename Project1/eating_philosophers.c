#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Three states in which philosophers can be
#define THINKING 0
#define HUNGRY 1
#define EATING 2

// Print_state function is responsible for printing the current state of a philosopher
void print_state(int philosopher, int state) {
    if (state == THINKING) {
        printf("Philosopher %d is thinking\n", philosopher);
    } else if (state == HUNGRY) {
        printf("Philosopher %d is hungry\n", philosopher);
    } else {
        printf("Philosopher %d is eating\n");
    }
}