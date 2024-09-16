#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 4

struct node {
  int page;
  struct node *next, *prev;
};

struct node *head = NULL;

void insert(int page) {
  struct node *new = malloc(sizeof(struct node));
  new->page = page;
  new->next = head;
  new->prev = NULL;
  if (head) head->prev = new;
  head = new;
}

void remove_node(struct node *node) {
  if (node->prev) node->prev->next = node->next;
  else head = node->next;
  if (node->next) node->next->prev = node->prev;
  free(node);
}

void update(int page) {
  struct node *temp = head;
  while (temp && temp->page != page) temp = temp->next;
  if (temp) {
    remove_node(temp);
    insert(page);
  }
}

void lru(int ref_string[], int n, int frames[]) {
  int page_faults = 0;
  for (int i = 0; i < n; i++) {
    struct node *temp = head;
    while (temp && temp->page != ref_string[i]) temp = temp->next;

    if (temp) update(ref_string[i]); // Move to front (recently used)
    else { // Page fault
      if (page_faults < MAX_FRAMES) insert(ref_string[i]);
      else {
        remove_node(head); // Remove least recently used (head)
        insert(ref_string[i]);
      }
      page_faults++;
    }

    printf("Ref %d: ", ref_string[i]);
    for (int j = 0; j < MAX_FRAMES; j++) {
      printf("%d ", head ? head->page : -1); // Print frame or "-"
      head = head ? head->next : NULL; // Print & move back
    }
    head = temp;
    printf("\n");
    fflush(stdout);  // Flush the output buffer after each reference
  }
  printf("Page Faults = %d\n", page_faults);
}

int main() {
  int ref_string[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
  int n = sizeof(ref_string) / sizeof(ref_string[0]);
  int frames[MAX_FRAMES];

  lru(ref_string, n, frames);

  return 0;
}
