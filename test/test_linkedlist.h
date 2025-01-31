#include "../linkedlist.h"

#ifndef __NUMBERS_H_
#define __NUMBERS_H_

void assert_equal(Element expectedValue, Element actualValue, char *message, Matcher matcher);
void assert_array_equal();

void test_create_list();

void test_empty_list_for_add_to_list();
void test_long_list_for_add_to_list();
void test_add_to_list();

void test_empty_list_for_add_to_start();
void test_long_list_for_add_to_start();
void test_add_to_start();

void test_invalid_position_for_insert_at();
void test_position_0_for_insert_at();
void test_add_to_end_for_insert_at();
void test_add_to_middle();
void test_for_insert_at();

void test_add_unique_element();
void test_existing_element_for_add_unique_element();
void test_for_add_unique();

void test_clear_list();

void test_remove_from_start_in_a_single_list();
void test_remove_from_long_list_for_remove_from_start();
void test_for_remove_from_start();

void test_remove_from_end_in_a_single_list();
void test_remove_from_end_int_long_list();
void test_for_remove_from_end();

void test_position0_for_remove_at();
void test_remove_from_middle();
void test_remove_from_end_for_remove_at();
void test_for_remove_at();

void test_single_occurrence();
void test_multiple_occurrence();
void test_for_remove_first_occurrence();

void test_empty_list_for_reverse();
void test_long_list_for_reverse();
void test_reverse();

void test_empty_array_for_map();
void test_non_empty_array_for_map();
void test_map();

void test_non_empty_array_for_filter();
void test_empty_array_for_filter();
void test_filter();

#endif