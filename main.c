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
  int number1 = 10, number2 = 20, number3 = 30, number4 = 40;
  int position = 1;
  add_to_start(list, &number1);
  add_to_list(list, &number3);
  insert_at(list, &number2, position);
  display_int_list(list);
  Element head = remove_from_start(list);
  printf("\n");
  display_int_list(list);

  Element tail = remove_from_end(list);
  printf("\n");
  display_int_list(list);

  Element element = remove_at(list, 0);
  printf("\n");
  display_int_list(list);

  return 0;
}
