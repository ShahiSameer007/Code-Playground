#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#define BUFFER_SIZE 10

typedef struct {
  int data;
  int is_producer; // Flag to identify producer or consumer
} item_t;

item_t buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t mutex, empty;

void *producer_consumer(void *arg) {
  item_t *item = (item_t *)arg;
  for (int i = 0; i < 10; i++) {
    if (item->is_producer) {
      item->data = rand() % 100; // Generate random item (producer)
      sem_wait(&empty);
      buffer[in] = *item;
      printf("Producer produced: %d\n", item->data);
      in = (in + 1) % BUFFER_SIZE;
    } else {
      sem_wait(&mutex);
      item->data = buffer[out].data;
      printf("Consumer consumed: %d\n", item->data);
      out = (out + 1) % BUFFER_SIZE;
      sem_post(&mutex);
    }
    sem_post(&empty);
  }
  return NULL;
}

int main() {
  sem_init(&mutex, 0, 1); // Initialize mutex for mutual exclusion (1)
  sem_init(&empty, 0, BUFFER_SIZE); // Initialize empty semaphore (buffer size)
  pthread_t threads[2];
  item_t items[2] = {{0, 1}, {0, 0}}; // Pre-define items with producer/consumer flags
  // Create producer and consumer threads with item arguments
  pthread_create(&threads[0], NULL, producer_consumer, &items[0]);
  pthread_create(&threads[1], NULL, producer_consumer, &items[1]);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  sem_destroy(&mutex);
  sem_destroy(&empty);
  return 0;
}
