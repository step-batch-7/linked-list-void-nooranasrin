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
  int number1 = 10, number2 = 21, number3 = 31, number4 = 40, number5 = 40, number6 = 50;
  int position = 1;
  Status status = add_to_start(list, &number1);
  status = add_to_list(list, &number3);
  status = add_to_list(list, &number4);
  status = insert_at(list, &number2, position);
  display_int_list(list);

  List_ptr reverse_list = reverse(list);
  printf("\nReverse:\n");
  display_int_list(reverse_list);

  status = add_unique(list, &number5, &is_int_equal);
  printf("\nAdd Unique Existing Element : %d\n", status);
  status = add_unique(list, &number6, &is_int_equal);
  printf("Add Unique Non Existing Element : %d\n", status);
  display_int_list(list);

  List_ptr incremented_numbers = map(reverse_list, &increment);
  printf("\nMap\n");
  display_int_list(incremented_numbers);

  List_ptr filtered_numbers = filter(reverse_list, &is_even);
  printf("\nFilter\n");
  display_int_list(filtered_numbers);

  int sum = 0;
  Element total = reduce(reverse_list, &sum, &add);
  printf("\nReduce : %d\n", *(int *)total);

  printf("\nForEach\n");
  forEach(reverse_list, &print_element);

  Element head = remove_from_start(list);
  printf("\n");
  display_int_list(list);

  Element tail = remove_from_end(list);
  printf("\n");
  display_int_list(list);

  Element element = remove_at(list, 0);
  printf("\n");
  display_int_list(list);

  status = clear_list(list);
  printf("\n");
  display_int_list(list);


  return 0;
}
