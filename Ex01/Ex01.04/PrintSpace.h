#pragma once
#include <stdio.h>

/// @brief prints a space the given length of times
/// @param length Length of spaces to be printed
void PrintSpace(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf(" ");
    }
}
