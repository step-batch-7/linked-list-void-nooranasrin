#include "../linkedlist.h"

#ifndef __NUMBERS_H_
#define __NUMBERS_H_

void assert_equal(Element expectedValue, Element actualValue, char *message, Matcher matcher);
void test_create_list();
void test_empty_list_for_add_to_list();
void test_long_list_for_add_to_list();
void test_add_to_list();

#endif