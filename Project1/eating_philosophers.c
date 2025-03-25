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
pthread_mutex_t *mutexes;   // Mutexes for each philosopher that will protect the access to their state
pthread_cond_t *conds;      // Condition variables for each philosopher to manage waiting for forks

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
    int left_philosopher = (philosopher + philosophers_number - 1) % philosophers_number;
    int right_philosopher = (philosopher + 1) % philosophers_number;

    pthread_mutex_lock(&mutexes[philosopher]);  // locking the philosopher's mutex to change its state and wait for forks
    state[philosopher] = HUNGRY;                // philosopher becomes hungry and wants to eat
    print_state(philosopher, HUNGRY);

    check(philosopher);                         // check if the philosopher can start eating

    // if the philosopher cannot eat immediately, they wait on their condition variable to be met
    while (state[philosopher] != EATING) {
        pthread_cond_wait(&conds[philosopher], &mutexes[philosopher]);
    }

    pthread_mutex_unlock(&mutexes[philosopher]); // unlock the philosopher's mutex after he is ready to eat
}


// Function that simulates a philosopher putting down the forks after eating
void put_forks(int philosopher) {
    int left_philosopher = (philosopher + philosophers_number - 1) % philosophers_number;
    int right_philosopher = (philosopher + 1) % philosophers_number;

    pthread_mutex_lock(&mutexes[philosopher]);  // locking the philosopher mutex to change his state
    state[philosopher] = THINKING;
    print_state(philosopher, THINKING);

    // check the left and right philosopher to see if they can start eating
    check(left_philosopher);
    check(right_philosopher);

    pthread_mutex_unlock(&mutexes[philosopher]); // unlock the philosophers mutex after updating the state
}

// Function that checks if a philosopher can start eating - both forks are available
void check(int philosopher) {
    int left_philosopher = (philosopher + philosophers_number - 1) % philosophers_number;
    int right_philosopher = (philosopher + 1) % philosophers_number;

    // check if the philosopher can eat, philosophers to his right and left cannot be eating
    if (state[philosopher] == HUNGRY && state[left_philosopher] != EATING && state[right_philosopher] != EATING) {
        state[philosopher] == EATING;               // philosopher can eat
        print_state(philosopher, EATING);
        pthread_cond_signal(&conds[philosopher]);   // signal the philosopher to proceed - change their state and start eating
    }
}

int main(int argc, char *argv[]) {

}