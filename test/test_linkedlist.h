#include "../linkedlist.h"

#ifndef __NUMBERS_H_
#define __NUMBERS_H_

void assert_equal(Element expectedValue, Element actualValue, char *message, Matcher matcher);

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

#endif