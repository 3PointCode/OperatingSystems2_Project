#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Three states in which philosophers can be
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int *state;                 // array to store the state of each philosopher
int philosophers_number;    // number of philosophers

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

// Function that simulates a philosopher taking the forks - starting to eat
void take_forks(int philosopher) {

}


// Function that simulates a philosopher putting down the forks after eating
void put_forks(int philosopher) {

}

// Function that checks if a philosopher can start eating - both forks are available
void check(int philosopher) {

}

int main(int argc, char *argv[]) {

}