#include <stdio.h>
#include <math.h> // for abs()

int main() {
  int n, head, max, i, direction = 1; // 1: right, -1: left
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
  }

  printf("Head Movement:\n");
  int total_seek = 0, current = head;

  for (i = 0; i < n && (direction == 1 ? current <= max : current >= 0); i++) {
    if (abs(arr[i] - current) > 0) {
      printf("  Move from %d to %d (seek %d)\n", current, arr[i], abs(arr[i] - current));
      total_seek += abs(arr[i] - current);
      current = arr[i];
    }
  }

  direction = -direction; // Reverse direction
  for (i = n - 1; i >= 0 && (direction == 1 ? current <= max : current >= 0); i--) {
    if (abs(arr[i] - current) > 0) {
      printf("  Move from %d to %d (seek %d)\n", current, arr[i], abs(arr[i] - current));
      total_seek += abs(arr[i] - current);
      current = arr[i];
    }
  }

  printf("Total Seek Time: %d\n", total_seek);

  return 0;
}
