/// @file Ex01.02
/// Author: Avraham Meyers
/// Course: C Workshop
/// Assignment: Homework 1, Question 2 

#include <stdio.h>
#include "CapitalizeChar.h"

int main() 
{
    char char_entry;
    scanf_s(" %c", &char_entry);

    while (char_entry != 'Q' && char_entry != 'q')
    {
        CapitalizeChar(char_entry);

        printf("%c\n", char_entry);
        scanf_s(" %c", &char_entry);
    }

    return 0;
}

