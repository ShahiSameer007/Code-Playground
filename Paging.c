#include <stdio.h>

int main() {
  int frame_size, page_size, processes, i, page, found = 0;
  int frames[100]; // Array for available memory frames

  printf("Enter frame size, page size, processes: ");
  scanf("%d %d %d", &frame_size, &page_size, &processes);

  for (i = 0; i < processes; i++) {
    printf("Process %d page requests (enter -1 to end):\n", i + 1);
    while (scanf("%d", &page) != EOF && page != -1) {
      found = 0; // Reset flag for each request
      for (int j = 0; j < 100; j++) { // Check if page already in memory
        if (frames[j] == page) {
          printf("  Hit\n");
          found = 1;
          break;
        }
      }

      if (!found) { // Page fault, simulate loading
        printf("  Fault, loading...\n");
        frames[0] = page; // FIFO replacement (overwrite first frame)
        for (int j = 1; j < 100; j++) { // Shift remaining frames (optional)
          frames[j] = frames[j - 1];
        }
      }
    }
  }

  return 0;
}
