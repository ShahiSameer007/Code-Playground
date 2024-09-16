#include <stdio.h>

int main() {
  int processes[] = {1, 2, 3};
  int n = sizeof(processes) / sizeof(processes[0]);
  int bt[] = {10, 5, 8};
  int wt = 0, tat = 0;

  printf("FCFS Scheduling Algorithm\n");
  printf("Process | Burst Time | Turn Around Time\n");
  for (int i = 0; i < n; i++) {
    tat = wt + bt[i];
    printf(" %d ", processes[i]);
    printf("|   %d      ", bt[i]);
    printf("|    %d \n", tat);
    wt = tat;
  }

  float avg_tat = (float)tat / n;
  printf("Average Turnaround Time = %f\n", avg_tat);
  return 0;
}
