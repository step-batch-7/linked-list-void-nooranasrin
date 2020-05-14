#include<stdio.h>
#include "test_linkedlist.h"

int main(void) {
  test_create_list();
  test_add_to_list();
  test_add_to_start();
  test_for_insert_at();
  test_for_add_unique();
  test_clear_list();
  test_for_remove_from_start();
  return 0;
}