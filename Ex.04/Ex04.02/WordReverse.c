#include <stdio.h>
#include "WordReverse.h"

int main(void)
{
    char string[] = "Hello there General Kenobi";
    
    printf("%s\n", string);

    WordReverse(string);
}

void WordReverse(char* string) {
    if (*string == '\0')
    {
        return;
    }

    char* substring = string;

    while (*substring != ' ' && *substring != '\0')
    {
        substring++;
    }
    if (*substring == ' ')
    {
        substring++;
    }
    WordReverse(substring);

    char* d = string;
    while (d != substring)
    {
        printf("%c", *d);
        ++d;
    }
    if (*substring == '\0')
    {
        printf(" ");
    }
}