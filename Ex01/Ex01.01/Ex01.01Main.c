/// @file Ex01.01
/// Author: Avraham Meyers
/// Course: C Workshop
/// Assignment: Homework 1, Question 1 

#include <stdio.h>

/// @brief inputs a char and then prints it, until the input is 'q' or 'Q'
int main()
{
    char input;
    scanf_s(" %c", &input);

    while (input != 'Q' && input != 'q') 
    {
        printf("%c\n", input);
        scanf_s(" %c", &input);
    }

    return 0;
}