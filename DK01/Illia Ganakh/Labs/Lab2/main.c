#include <stdio.h>
#include "list.h"

int main(void) {
  IntList *list = createIntList();

  addRandIntValuesToIntList(list, 8);
  
  for(int i = 0; i < 2; i++) {
  printIntList(list);
  printReverseIntList(list);
  }
  
  deleteIntList(list);
}