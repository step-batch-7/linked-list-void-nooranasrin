#include<stdio.h>
#include<stdlib.h>
#include "test_linkedlist.h"

void test_create_list() {
  printf("--------------create_list-------------\n");
  char description[] = "should create a list with length 0\n";
  List_ptr list = create_list();
  assert_int_equal(0, list->length, description);
  printf("\n");
}

void test_empty_list_for_add_to_list() {
  char description[] = "should add to the 0th position of an empty list\n";
  List_ptr list = create_list();
  int number = 5;
  Status actual = add_to_list(list, &number);
  assert_int_equal(1, actual, description);
}

void test_long_list_for_add_to_list() {
  char description[] = "should add to the end of a long list\n";
  List_ptr list = create_list();
  int num1 = 1, num2 = 2, num3 = 4;
  add_to_start(list, &num1);
  add_to_start(list, &num2);
  Status actual = add_to_list(list, &num3);
  assert_int_equal(1, actual, description);
}

void test_add_to_list() {
  printf("--------- add_to_list---------\n");
  test_empty_list_for_add_to_list();
  test_long_list_for_add_to_list();
  printf("\n");
}