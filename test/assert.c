#include "test_linkedlist.h"

void assert_equal(Element expectedValue, Element actualValue, char *message, Matcher matcher) {
  char symbol[] = "✅";

  if(matcher(expectedValue, actualValue) ) {
    printf("%s %s",symbol, message);
    return;
  }
  char error_symbol[] = "❌";
  printf("%s %s\n",error_symbol, message);
}

void assert_array_equal(List_ptr *expectedValue, List_ptr *actualValue, char *message, Matcher matcher) {
  char symbol[] = "✅";

  if(matcher(expectedValue, actualValue) ) {
    printf("%s %s",symbol, message);
    return;
  }
  char error_symbol[] = "❌";
  printf("%s %s",error_symbol, message);
}
