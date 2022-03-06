#include <malloc.h>
#include <stdio.h>

// Structure of the list
struct link {
  int info;
  struct link* next;
};

// Function to create a header linked list
struct link* create_header_list(int data) {
  // Create a new node
  struct link *new_node, node;
  new_node = (struct link*)malloc(sizeof(struct link));
  new_node->info = data;
  new_node->next = NULL;

  // If it is the first node
  if (start == NULL) {
    // Initialize the start
    start = (struct link)malloc(sizeof(struct link));
    start->next = new_node;
  } else {
    // Insert the node in the end
    node = start;
    while (node->next != NULL) {
      node = node->next;
    }
    node->next = new_node;
  }
  return start;
}

// Function to display the
// header linked list
void display(struct link* llist) {
  struct link* node;
  node = llist;
  node = node->next;
  while (node != NULL) {
    printf("%d ", node->info);
    node = node->next;
  }
  printf("\n");
}

// Driver code
int main() {
  struct link* llist = NULL;
  llist = create_header_list(11);
  display(llist);

  return 0;
}
