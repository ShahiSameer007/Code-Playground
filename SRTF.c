#include <stdio.h>

struct Process {
  int pid;
  int bt;
};

int compare(const void *a, const void *b) {
  struct Process *p1 = (struct Process *)a;
  struct Process *p2 = (struct Process *)b;
  return p1->bt - p2->bt;
}

void findTurnAroundTime(struct Process proc[], int n) {
  int current_time = 0;
  int completed = 0;

  while (completed != n) {
    int min_index = -1;

    // Find the process with the shortest burst time among arrived processes
    for (int i = 0; i < n; i++) {
      if (proc[i].bt > 0 && (min_index == -1 || proc[proc[min_index].pid].bt > proc[i].bt))
        min_index = i;
    }

    // Reduce burst time and check for completion
    proc[min_index].bt--;
    if (proc[min_index].bt == 0)
      completed++;

    // Increase current time and update waiting time for non-completed processes
    current_time++;
    for (int i = 0; i < n; i++) {
      if (i != min_index && proc[i].bt > 0)
        proc[i].bt--; // This implicitly calculates waiting time
    }

    // Sort processes by burst time again if needed (preemption)
    qsort(proc, n, sizeof(proc[0]), compare);
  }

  // Calculate turnaround time (derived from current_time)
  printf("Process | Burst Time | Turn Around Time\n");
  for (int i = 0; i < n; i++) {
    printf(" %d ", proc[i].pid);
    printf("|   %d      ", proc[i].bt);
    printf("|    %d \n", current_time);
  }

  // Average turnaround time can be calculated from the data if needed
}

int main() {
  struct Process proc[] = {{1, 7}, {2, 5}, {3, 3}};
  int n = sizeof(proc) / sizeof(proc[0]);

  printf("SRTF Scheduling Algorithm\n");
  findTurnAroundTime(proc, n);
  return 0;
}
