#include <stdio.h>
#include "list.h"

int main()
{
    FILE *flow = fopen("test.txt", "r");

    char tmpCharacter;

    Row *tmpRow = createRow();

    while ((tmpCharacter = fgetc(flow)) != EOF)
    {
        if (tmpCharacter == '\n')
        {
            printReverseRow(tmpRow);

            deleteRow(tmpRow);

            tmpRow = createRow();
        }

        else
        {
            addCharacterToRow(tmpRow, tmpCharacter);
        }
    }

    printReverseRow(tmpRow);

    deleteRow(tmpRow);

    fclose(flow);

    return 0;

}
