#pragma once
#include <stdio.h>

/// @brief prints a star(*) the given length number of times
/// @param length Number of stars(*) to be printed
void PrintStar(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", '*');
    }
}