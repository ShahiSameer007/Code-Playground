#include <stdio.h>
#include <stdlib.h> // for abs() function

int main() {
  int n, head, total_seek_time = 0;
  int arr[100];

  printf("Enter the number of requests: ");
  scanf("%d", &n);

  printf("Enter the head position: ");
  scanf("%d", &head);

  printf("Enter the request sequence: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Calculate seek time for each request
  for (int i = 0; i < n; i++) {
    int seek_time = abs(arr[i] - head);
    total_seek_time += seek_time;
    printf("Seek Time for request %d: %d\n", i + 1, seek_time);
    head = arr[i]; // Update head position after each request
  }

  printf("Total Seek Time: %d\n", total_seek_time);

  return 0;
}