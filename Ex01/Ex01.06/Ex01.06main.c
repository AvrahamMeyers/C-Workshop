/// @file Ex01.06
/// Author: Avraham Meyers
/// Course: C Workshop
/// Assignment: Homework 1, Question 6

#include <stdio.h>
#include "CheckDigit.h"

int main()
{
    printf("enter 8 digit ID\n");

    int ID;
    scanf_s("%d", &ID);
    
    int check_digit = CheckDigit(ID);
    ID *= 10;
    ID += check_digit;

    printf("your 9 digit ID number is: %d\n", ID);

    return 0;

}

