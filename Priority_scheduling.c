#include <stdio.h>
struct Process {
  int pid;
  int bt;
  int priority;
  int wt, tat; // Waiting and turnaround time (calculated during scheduling)
};
int compare(const void *a, const void *b) {
  struct Process *p1 = (struct Process *)a;
  struct Process *p2 = (struct Process *)b;
  return p2->priority - p1->priority; // Sort by priority (descending)
}
void findTurnAroundTime(struct Process proc[], int n) {
  int current_time = 0, completed = 0;
  while (completed != n) {
    int min_index = -1;
    for (int i = 0; i < n; i++) {
      if (proc[i].bt > 0 && (min_index == -1 || proc[proc[min_index].pid].priority < proc[i].priority))
        min_index = i;
    }
    if (min_index == -1) {
      current_time++;
      continue;
    }
    proc[min_index].bt--;
    if (proc[min_index].bt == 0) {
      completed++;
      proc[min_index].tat = current_time + 1;
      proc[min_index].wt = proc[min_index].tat - proc[min_index].bt;
    }
    current_time++;
  }
}
void printResult(struct Process proc[], int n) {
  printf("Process | Burst Time | Priority | Waiting Time | Turn Around Time\n");
  for (int i = 0; i < n; i++)
    printf(" %d ", proc[i].pid), printf("|   %d      ", proc[i].bt),
      printf("|     %d    ", proc[i].priority), printf("|    %d     ", proc[i].wt),
      printf("|    %d \n", proc[i].tat);
}
int main() {
  struct Process proc[] = {{1, 10, 2}, {2, 5, 1}, {3, 8, 3}};
  int n = sizeof(proc) / sizeof(proc[0]);
  printf("Priority Scheduling (Non-Preemptive)\n");
  qsort(proc, n, sizeof(proc[0]), compare); // Sort by priority (in-place)
  findTurnAroundTime(proc, n);
  printResult(proc, n);
  return 0;
}
