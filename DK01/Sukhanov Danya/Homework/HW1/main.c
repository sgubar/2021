#include "dk_tool.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	int roz =0;
	printf("Enter the dimensions of your matrices: ");
    scanf("%d",&roz);
    
    int array1[roz][roz];
    
    int array2[roz][roz];
    
    for(int i=0; i<roz; i++){
	
    for(int j=0; j<roz; j++)
    {
    array1[i][j] = rand() % 10;
    array2[i][j] = rand() % 10;
    }
    }	
	printf("Drawing your matrices \n \n");
	
	for(int i=0; i<roz; i++)
    {
        
    for(int j=0; j<roz; j++)
    {
    printf("%2d ",array1[i][j]);
    }
    
    printf("\n");
    }
    
	printf("\n");
	
	for(int i=0; i<roz; i++)
    {
    
    for(int j=0; j<roz; j++)
    {
    printf("%2d ",array2[i][j]);
    }
    
    printf("\n");
    }
	
	multiplication( roz, array1, array2);
	
	printf("\n");
	
	printf("Answer:");
	
	printf("\n");
	
    for(int i=0; i<roz; i++)
    {
    for(int j=0; j<roz; j++)
    {
    printf("%2d ",array_multi[i][j]);
    }
    printf("\n");
    }
	
	return 0;
}
