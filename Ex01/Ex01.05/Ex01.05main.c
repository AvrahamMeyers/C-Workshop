/// @file Ex01.05
/// Author: Avraham Meyers
/// Course: C Workshop
/// Assignment: Homework 1, Question 5

#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "IDCheck.h"

int main()
{
    printf("enter an ID to validate\n");

    int ID = 0;
    scanf_s("%d", &ID);

    bool validID = IDCheck(ID);

    if (validID == true)
    {
        printf("the ID is valid\n");
    }
    else
    {
        printf("the ID is not valid\n");
    }

    return 0;
}

