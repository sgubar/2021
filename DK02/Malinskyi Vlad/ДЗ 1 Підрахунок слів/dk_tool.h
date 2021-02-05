#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED


int func(char* s)
{
    int count, i;
    count = 0;
    for (i = 0; i<strlen(s); i++)
    {   if(isdigit(s[i]))
            {
            printf("Vvedite tol'ko slova");
            printf("\n");
            return 0;
            }
        if ((s[i] == ' ') && (s[i+1] != ' '))
        {
            count = count + 1;
        }
    }
    printf("V predlojenii: %d slov", count+1);
    return 0;
}
#endif // FUNCTION_H_INCLUDED
