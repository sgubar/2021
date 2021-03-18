#include <stdio.h>
#include "list.h"

int main(void) {
  IntList *list = createIntList();
  int chislo;
  printf("Enter size of list, please ");
  scanf("%d", &chislo);

  MakeListSizeAndAddValues(list, chislo);
  
  for(int i = 0; i < 2; i++) {
  printlist(list);
  Reverse(list);
  }
  
  delete(list);
}
