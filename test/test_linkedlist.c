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
