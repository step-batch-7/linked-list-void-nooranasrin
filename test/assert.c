#include "test_linkedlist.h"

void assert_int_equal(int expectedValue, int actualValue, char *message) {
  char symbol[] = "✅";

  if(expectedValue != actualValue ) {
    char error_symbol[] = "❌";
    printf("%s %s  * Expected -> %d\n  * Got -> %d\n",error_symbol, message, expectedValue, actualValue);
    return;
  }

  printf("%s %s",symbol, message);
}
