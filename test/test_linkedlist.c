#include<stdio.h>
#include<stdlib.h>
#include "test_linkedlist.h"

Status is_int_equal(Element num1, Element num2) {
  return *(int *)num1 == *(int *)num2;
}

void test_create_list() {
  printf("--------------create_list-------------\n");
  char description[] = "should create a list with length 0\n";
  List_ptr list = create_list();
  Status expected = Failure;
  assert_equal(&expected, &list->length, description, &is_int_equal);
  printf("\n");
}

void test_empty_list_for_add_to_list() {
  char description[] = "should add to the 0th position of an empty list\n";
  List_ptr list = create_list();
  int number = 5;
  Status actual = add_to_list(list, &number);
  Status expected = Success;
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_long_list_for_add_to_list() {
  char description[] = "should add to the end of a long list\n";
  List_ptr list = create_list();
  int num1 = 1, num2 = 2, num3 = 4;
  add_to_start(list, &num1);
  add_to_start(list, &num2);
  Status actual = add_to_list(list, &num3);
  Status expected = Success;
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_add_to_list() {
  printf("--------- add_to_list---------\n");
  test_empty_list_for_add_to_list();
  test_long_list_for_add_to_list();
  printf("\n");
}

void test_empty_list_for_add_to_start() {
  char description[] = "should add to the 0th position of an empty list\n";
  List_ptr list = create_list();
  int number = 5;
  Status actual = add_to_start(list, &number);
  Status expected = Success;
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_long_list_for_add_to_start() {
  char description[] = "should add to the start of a long list\n";
  List_ptr list = create_list();
  int num1 = 1, num2 = 2, num3 = 4;
  add_to_start(list, &num1);
  add_to_start(list, &num2);
  Status actual = add_to_start(list, &num3);
  Status expected = Success;
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_add_to_start() {
  printf("--------- add_to_start---------\n");
  test_empty_list_for_add_to_start();
  test_long_list_for_add_to_start();
  printf("\n");
}