#include "dk_tool.h"

#define OCT 8          // Êîíñòàíòà ÷èñòî äëÿ íàïåğåä çàãîòîâëåíèõ ôîğìóë        

int Convert_Oct_to_Dec(char* arr)        // Íàøà ôóíêö³ÿ ÿêà îòğèìóº ìàñèâ arr (ñêîğî÷åííÿ â³ä array)
{
    int dec = 0, counter_stepen = 0;
    for (int i = strlen_buffer(arr) - 1; i >= 0; i--)     // Òîé ñàìèé àëãîğèòì ÿêèé äîçâîëÿº íå ïèñàòè çàéâ³ íóë³ (äèâ. 59 ñòğîêó)
    {
        if ((arr[i] > 47) && (arr[i] < 56))
        {
            arr[i] -= 48;
        }
        else
        {
            printf("Ââåäèòå êîğåêòíûå äàííûå");
            return -1;
        }
        dec += arr[i] * stepen(OCT, counter_stepen);
        counter_stepen++;
    }
    return dec;     // Îñê³ëüêè ôóíêö³ÿ òèïó int - íàøà ôóíêöèÿ ïîâåğòàº ÷èñëî ó äåñÿòêîâ³é ôîğì³
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