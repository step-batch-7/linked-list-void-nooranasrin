#include<stdio.h>
#include "linkedlist.h"

Element increment(Element number) {
  char *incremented_number = malloc(sizeof(char));
  *incremented_number = *(int *)number + 1;
  return incremented_number;
}

Status is_even(Element number) {
  return *(int *)number % 2 == 0 ? Success : Failure;
}

Status is_int_equal(Element num1, Element num2) {
  return *(int *)num1 == *(int *)num2;
}

Element add(Element sum, Element number) {
  int *total = malloc(sizeof(int));
  *total = *(int *)sum + *(int *)number;
  return (sum = total);
}

void print_element(Element element) {
  printf("%d\n", *(int *)element);
}

void display_int_list(List_ptr list) {
  Node_ptr pWalk = list->first;

  while (pWalk != NULL) {
    printf("%d\n", *(int *)pWalk->element);
    pWalk = pWalk->next;
  }
}

int main() {
  List_ptr list = create_list();
  int number1 = 10, number2 = 20, number3 = 30, number4 = 40, number5 = 50, number6 = 60;
  // Status status = add_to_start(list, &number1);
  // status = add_to_list(list, &number2);
  // status = add_to_list(list, &number3);
  // status = add_to_list(list, &number4);
  // status = add_to_list(list, &number5);
  // status = add_to_list(list, &number6);
  display_int_list(list);
  Element element = remove_at(list, 0);
  // printf("\n%d\n\n", *(int *)element);
  display_int_list(list);
  return 0;
}
