#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define N 2 // Number of philosophers (explicitly set to 2)
int turn = 0; // Shared variable for turn (initially philosopher 0)

void *philosopher(void *arg) {
  int id = *(int*)arg; // Get the philosopher ID from the argument

  // Single eating cycle
  while (1) {
    // Busy waiting (simple approach, not ideal for real-world scenarios)
    while (turn != id) {}

    // Philosopher actions
    printf("Philosopher %d thinks\n", id + 1);
    sleep(1); // Thinking (fixed time for simplicity)

    printf("Philosopher %d eats\n", id + 1);
    sleep(2); // Eating (fixed time for simplicity)

    // Pass the turn to the other philosopher
    turn = (id + 1) % N;
  }

  return NULL;
}

int main() {
  pthread_t threads[N];
  int i;

  // Create philosopher threads
  for (i = 0; i < N; i++) {
    pthread_create(&threads[i], NULL, philosopher, &i);
  }

  // Wait for all threads to finish (may not terminate in this implementation)
  for (i = 0; i < N; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
