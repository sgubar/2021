#include <stdio.h>
#include "list1.h"

int main(){
    FILE *flow = fopen("test1.txt", "r");
    char tmpCharacter;
    Row *tmpRow = createRow();

    while ((tmpCharacter = fgetc(flow)) != EOF){
        if (tmpCharacter == '\n'){
            printReverseRow(tmpRow);
            deleteRow(tmpRow);
            tmpRow = createRow();
        }

        else{
            addCharacterToRow(tmpRow, tmpCharacter);
        }
    }

    printReverseRow(tmpRow);
    deleteRow(tmpRow);
    fclose(flow);
    return 0;
}
