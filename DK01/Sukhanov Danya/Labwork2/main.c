#include <stdio.h>
#include "list.h"

int main(void) {
  IntList *list = createIntList();
  int chislo;
  printf("Enter size of list, please ");
  scanf("%d", &chislo);

  addRandIntValuesToIntList(list, chislo);
  
  for(int i = 0; i < 2; i++) {
  printIntList(list);
  printReverseIntList(list);
  }
  
  deleteIntList(list);
}
