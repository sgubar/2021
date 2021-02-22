#include "dk_tool.h"

int multiplication(int roz, int array1[][roz], int array2[][roz]){

	
	int mult=0;
	
	for(int i=0; i<roz; i++){
	
    for(int j =0; j<roz; j++)
    {
    for(int tr=0; tr<roz; tr++)
    mult = mult + array1[i][tr] * array2[tr][j];
    array_multi[i][j] = mult;
    mult = 0;
    }
	}		
    return 0;
	
}
