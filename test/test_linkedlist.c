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

void test_invalid_position_for_insert_at() {
  char description[] = "should give Failure when the position is not valid\n";
  List_ptr list = create_list();
  int number = 5;
  Status expected = Failure;
  Status actual = insert_at(list, &number, 3);
  assert_equal(&expected, &actual, description, &is_int_equal);
  actual = insert_at(list, &number, -3);
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_position_0_for_insert_at() {
  char description[] = "should add the element into the 0th position when the position is 0\n";
  List_ptr list = create_list();
  int number = 5;
  Status expected = Success;
  Status actual = insert_at(list, &number, 0);
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_add_to_end_for_insert_at() {
  char description[] = "should add the element into the end of the list when the position is equal to the length of the list\n";
  List_ptr list = create_list();
  int number1 = 1, number2 = 3, number3 = 5;
  Status expected = Success;
  add_to_start(list , &number1);
  add_to_start(list, &number2);
  Status actual = insert_at(list, &number3, 2);
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_add_to_middle() {
  char description[] = "should add to the list when the position is in between 0 and length of the list\n";
  List_ptr list = create_list();
  int number1 = 1, number2 = 3, number3 = 5;
  Status expected = Success;
  add_to_start(list , &number1);
  add_to_start(list, &number2);
  Status actual = insert_at(list, &number3, 1);
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_for_insert_at() {
  printf("--------- insert_at---------\n");
  test_invalid_position_for_insert_at();
  test_position_0_for_insert_at();
  test_add_to_end_for_insert_at();
  test_add_to_middle();
  printf("\n");
}

void test_add_unique_element() {
  char description[] = "should add the element into the end of the list when the element is not existing\n";
  int num1 = 1, num2 = 2, num3 = 3;
  List_ptr list = create_list();
  add_to_start(list , &num1);
  add_to_start(list, &num2);
  Status actual = add_unique(list, &num3, &is_int_equal);
  Status expected = Success;
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_existing_element_for_add_unique_element() {
  char description[] = "should not add the element into list when the element is existing\n";
  List_ptr list = create_list();
  int num1 = 1, num2 = 2;
  add_to_start(list , &num1);
  add_to_start(list, &num2);
  Status actual = add_unique(list, &num1, &is_int_equal);
  Status expected = Failure;
  assert_equal(&expected, &actual, description, &is_int_equal);
}

void test_for_add_unique() {
  printf("---------add_unique---------\n");
  test_add_unique_element();
  test_existing_element_for_add_unique_element();
  printf("\n");
}

void test_clear_list() {
  printf("---------clear_list---------\n");
  char description[] = "should clear the list\n";
  List_ptr list = create_list();
  int num1 = 1, num2 = 2;
  add_to_start(list, &num1);
  add_to_start(list, &num2);
  Status actual = clear_list(list);
  Status expected = Success;
  assert_equal(&expected, &actual, description, &is_int_equal);
  printf("\n");
}

void test_remove_from_start_in_a_single_list() {
  char description[] = "should remove from start in a single list\n";
  List_ptr list = create_list();
  int num = 1;
  add_to_list(list, &num);
  Element actual = remove_from_start(list);
  int expected = 1;
  assert_equal(&expected, actual, description, &is_int_equal);
}

void test_remove_from_long_list_for_remove_from_start() {
  char description[] = "should remove from start in a long list\n";
  List_ptr list = create_list();
  int num = 1, num2;
  add_to_list(list, &num);
  add_to_list(list, &num2);
  Element actual = remove_from_start(list);
  int expected = 1;
  assert_equal(&expected, actual, description, &is_int_equal);
}

void test_for_remove_from_start() {
  printf("---------remove_from_start---------\n");
  test_remove_from_start_in_a_single_list();
  test_remove_from_long_list_for_remove_from_start();
  printf("\n");
}

void test_remove_from_end_in_a_single_list() {
  char description[] = "should remove from start in a single list\n";
  List_ptr list = create_list();
  int num = 1;
  add_to_list(list, &num);
  Element actual = remove_from_end(list);
  int expected = 1;
  assert_equal(&expected, actual, description, &is_int_equal);
}

void test_remove_from_end_int_long_list() {
  char description[] = "should remove from end in a long list\n";
  List_ptr list = create_list();
  int num = 1, num2 = 2;
  add_to_list(list, &num);
  add_to_list(list, &num2);
  Element actual = remove_from_end(list);
  int expected = 2;
  assert_equal(&expected, actual, description, &is_int_equal);
}

void test_for_remove_from_end() {
  printf("---------remove_from_end---------\n");
  test_remove_from_end_in_a_single_list();
  test_remove_from_end_int_long_list();
  printf("\n");
}

void test_position0_for_remove_at() {
  char description[] = "should remove from start when the position is 0\n";
  List_ptr list = create_list();
  int num = 1;
  add_to_list(list, &num);
  Element actual = remove_at(list, 0);
  int expected = 1;
  assert_equal(&expected, actual, description, &is_int_equal);
}

void test_remove_from_middle() {
  char description[] = "should remove from the given position when the position is valid and in between 0 and length of the list\n";
  List_ptr list = create_list();
  int num = 1, num2 = 2, num3 = 3;
  add_to_list(list, &num);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  Element actual = remove_at(list, 1);
  int expected = 2;
  assert_equal(&expected, actual, description, &is_int_equal);
}

void test_remove_from_end_for_remove_at() {
  char description[] = "should remove from the end when the position is equal to the length of the list\n";
  List_ptr list = create_list();
  int num = 1, num2 = 2, num3 = 3;
  add_to_list(list, &num);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  Element actual = remove_at(list, 2);
  int expected = 3;
  assert_equal(&expected, actual, description, &is_int_equal);
}

void test_for_remove_at() {
  printf("---------remove_at---------\n");
  test_position0_for_remove_at();
  test_remove_from_middle();
  test_remove_from_end_for_remove_at();
  printf("\n");
}
