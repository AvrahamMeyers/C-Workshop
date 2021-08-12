/// @file Ex01.04
/// Author: Avraham Meyers
/// Course: C Workshop
/// Assignment: Homework 1, Question 4

#pragma once
#include <stdio.h>
#include "PrintDiamond.h"

int main()
{
    int base = 0;

    do
    {
        printf("enter odd number for the base of the diamond\n");
        printf("enter 0 to exit\n");

        scanf_s("%d", &base);

        if (base % 2 != 0)
        {
            PrintDiamond(base);
        }

    } while (base != 0);

    return 0;
}