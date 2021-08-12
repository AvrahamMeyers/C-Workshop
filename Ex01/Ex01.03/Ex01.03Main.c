#include <stdio.h>

int strlen(const char* begin);

int main()
{
    printf("enter a string to read the length of\n");

    char *string;
    scanf_s("%s", string);

    int length = strlen(string);

    printf("the length of the string is %d\n", length);

    return 0;
}


int strlen(const char *begin) 
{
    int length = 0;

    for (char *index = begin; index != NULL; index++) 
    {
        ++length;
    }

    return length;
}