#include <stdio.h>
#include <stdlib.h>
#include "Transpose.h"

#define SIZE 4

void TransposeMatrix(size_t **matrix, numeric_t length)
{
    for (size_t row = 0; row < length; row++)
    {
        for (size_t column = 0; column < row; column++)
        {
            size_t *a = &matrix[row][column];
            size_t *b = &matrix[column][row];
            swap(a, b);
        }
    }
}

void swap(size_t *a, size_t *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void PrintMatrix(size_t** matrix, numeric_t length) {
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    numeric_t **matrix = (int **)malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++)
    {
        matrix[i] = (int *)malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = j;
            //scanf_s("%d", &(matrix[i][j]));
        }
    }

    PrintMatrix(matrix, SIZE);

    TransposeMatrix(matrix, SIZE);

    printf("the transpose of the matrix is:\n");

    PrintMatrix(matrix, SIZE);

    return 0;
}





