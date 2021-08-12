#pragma once
#include <stdio.h>
#include "PrintSpace.h"
#include "PrintStar.h"

/// @brief prints a diamond of '*' with the given base size
/// @param base Base length of the diamond
void PrintDiamond(int base)
{
    int initial_space_size = base / 2;

    for (int star_count = 1; star_count <= base; star_count += 2)
    {
        PrintSpace(initial_space_size--);
        PrintStar(star_count);
        printf("\n");
    }

    initial_space_size = 1;

    for (int star_count = base - 2; star_count >= 1; star_count -= 2)
    {
        PrintSpace(initial_space_size++);
        PrintStar(star_count);
        printf("\n");
    }
}