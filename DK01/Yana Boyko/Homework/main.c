#include "dk_tool.h"

int main()
{
    int num_up, rows, cols;
    printf("Enter number of rows:");
    scanf("%d", &rows);
    printf("\nEnter number of cols: ");
    scanf("%d", &cols);
    
    int** array = create_array(rows, cols);
    fill_array(array, rows, cols);
    print_array(array, rows, cols);
    
    printf("Random array generated\nEnter the value of multiplicator: ");
    scanf("%d", &num_up);
    array_up(array, rows, cols, num_up);
    
    print_array(array, rows, cols);
    delete_array(array, rows);
}
