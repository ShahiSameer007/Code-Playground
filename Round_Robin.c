#include <stdio.h>
struct Process {
  int pid, bt, at, wt, tat;
};
int compareArrival(const void *a, const void *b) {
  struct Process *p1 = (struct Process *)a;
  struct Process *p2 = (struct Process *)b;
  return p1->at - p2->at; // Sort by arrival time
}
void RR(struct Process proc[], int n, int quantum) {
  int current_time = 0, completed = 0;
  while (completed != n) {
    int min_index = -1;
    for (int i = 0; i < n; i++) {
      if (proc[i].at <= current_time && proc[i].bt > 0 && (min_index == -1 || proc[proc[min_index].pid].bt < proc[i].bt))
        min_index = i;
    }
    if (min_index == -1) {
      current_time++;
      continue;
    }
    if (proc[min_index].bt <= quantum) {
      current_time += proc[min_index].bt;
      proc[min_index].bt = 0;
      proc[min_index].tat = current_time - proc[min_index].at;
      proc[min_index].wt = proc[min_index].tat - proc[min_index].bt;
      completed++;
    } else {
      current_time += quantum;
      proc[min_index].bt -= quantum;
    }}}
void printResult(struct Process proc[], int n) {
  printf("Process | Burst Time | Arrival Time | Waiting Time | Turn Around Time\n");
  for (int i = 0; i < n; i++)
    printf(" %d ", proc[i].pid), printf("|   %d      ", proc[i].bt),
      printf("|     %d     ", proc[i].at), printf("|    %d     ", proc[i].wt),
      printf("|    %d \n", proc[i].tat);
}
int main() {
  struct Process proc[] = {{1, 7, 0}, {2, 5, 1}, {3, 3, 2}};
  int n = sizeof(proc) / sizeof(proc[0]);
  int quantum = 2;
  printf("Round Robin Scheduling\n");
  qsort(proc, n, sizeof(proc[0]), compareArrival); // Sort by arrival time
  RR(proc, n, quantum);
  printResult(proc, n);
  return 0;
}
