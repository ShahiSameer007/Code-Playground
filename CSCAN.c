#include <stdio.h>
#include <math.h> // for abs()

int main() {
  int n, head, max, i, leftmost = -1;
  int arr[100];

  printf("Enter requests, head, max cylinder: ");
  scanf("%d %d %d", &n, &head, &max);

  printf("Enter request sequence: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] < 0 || arr[i] > max) {
      printf("Invalid request: %d (out of range)\n", arr[i]);
      return 1;
    }
    if (leftmost == -1 || arr[i] < leftmost) {
      leftmost = arr[i]; // Update leftmost request
    }
  }

  printf("Head Movement:\n");
  int total_seek = 0, current = head;

  // Move right, serve requests
  for (i = 0; i < n && current <= max; i++) {
    if (abs(arr[i] - current) > 0) {
      printf("  Move from %d to %d (seek %d)\n", current, arr[i], abs(arr[i] - current));
      total_seek += abs(arr[i] - current);
      current = arr[i];
    }
  }

  // Seek to leftmost request (without serving)
  current = max;
  if (leftmost != -1) {
    printf("  Move from %d to %d (seek %d)\n", current, leftmost, abs(leftmost - current));
    total_seek += abs(leftmost - current);
    current = leftmost;
  }

  // Move left, serve requests
  for (i = n - 1; i >= 0 && current >= 0; i--) {
    if (abs(arr[i] - current) > 0) {
      printf("  Move from %d to %d (seek %d)\n", current, arr[i], abs(arr[i] - current));
      total_seek += abs(arr[i] - current);
      current = arr[i];
    }
  }

  printf("Total Seek Time: %d\n", total_seek);

  return 0;
}
