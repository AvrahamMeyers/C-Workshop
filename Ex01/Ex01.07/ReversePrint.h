#pragma once

#include <stdio.h>

/// @brief inputs numbers and prints them in reverse order
/// @param x the previous number entered
void ReversePrint(int x)
{
    scanf_s("%d", &x);

    if (x != 0)
    {
        ReversePrint(x);

        printf("%d ", x);
    }
}