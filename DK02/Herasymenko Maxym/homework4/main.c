#include"single_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    Single_listCharElement *list = createCharSingle_list();
    addCharValue(list, 'I');
    addCharValue(list, 'Q');

	printCharSingle_list(list);

	removeCharElementfromList_usingIndex(list, 0);
	printCharSingle_list(list);

    insertCharElementtoList_usingIndex(list, 0, 'I');
    printCharSingle_list(list);

    deleteCharSingle_list(list);


}
