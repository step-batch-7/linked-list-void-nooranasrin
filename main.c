#include<stdio.h>
#include "linkedlist.h"

void display_int_list(List_ptr list) {
  Node_ptr pWalk = list->first;

  while (pWalk != NULL) {
    printf("%d\n", *(int *)pWalk->element);
    pWalk = pWalk->next;
  }
}

int main() {
  List_ptr list = create_list();
  int number = 10;
  add_to_start(list, &number);
  display_int_list(list);
  return 0;
}
