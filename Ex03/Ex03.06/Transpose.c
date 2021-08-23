#pragma once
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Transpose.h"

#define SIZE 4

int TransposeMatrix(numeric_t** matrix, numeric_t length)
{
    //return 1 if matrix is symmetric, 2 if it is skew symmetric, 3 if it is neither

    bool symmetric = true;
    bool skew = true;

    for (int row = 0; row < length; row++)
    {
        for (int column = 0; column < row; column++)
        {
            numeric_t* a = &matrix[row][column];
            numeric_t* b = &matrix[column][row];
            if (*a != *b)
            {
                symmetric = false;
            }
            if (*a != (-1) * (*b))
            {
                skew = false;
            }
            swap(a, b);
        }
    }

    if (symmetric)
    {
        return 1;
    }
    else if (skew)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void swap(numeric_t* a, numeric_t* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void PrintMatrix(numeric_t** matrix, numeric_t length) {
    for (numeric_t i = 0; i < SIZE; i++)
    {
        for (numeric_t j = 0; j < SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

