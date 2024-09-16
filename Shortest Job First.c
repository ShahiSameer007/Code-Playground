//Non-Preemptive Shortest Job First
#include <stdio.h>

struct Process {
    int burst;  // Burst time
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input burst times
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst);
    }

    // Sort processes based on burst time (SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].burst > proc[j + 1].burst) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    // Display sorted burst times
    printf("Sorted burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: Burst time = %d\n", i + 1, proc[i].burst);
    }

    return 0;
}
