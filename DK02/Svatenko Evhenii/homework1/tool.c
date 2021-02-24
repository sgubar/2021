#include "tool.h"

#define OCT 4                 

int Convert_Oct_to_Dec(char* arr)        
{
    int dec = 0, counter_stepen = 0;
    for (int i = strlen_buffer(arr) - 1; i >= 0; i--)     
    {
        if ((arr[i] > 47) && (arr[i] < 56))
        {
            arr[i] -= 48;
        }
        else
        {        
            return -1;
        }
        dec += arr[i] * stepen(OCT, counter_stepen);
        counter_stepen++;
    }
    return dec;     
}

int strlen_buffer(char* buffer)
{
    int res = 0;
    while ((*buffer != '\n') && (*buffer != '\0'))
    {
        buffer++;
        res++;
    }
    return res;
}

int stepen(int x, int a)
{
    int result = 1;
    for (int i = 0; i < a; i++)
    {
        result *= x;
    }
    return result;
}
