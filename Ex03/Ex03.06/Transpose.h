#pragma once

/// @brief specifier for int
typedef int numeric_t;

/// @brief transposes a square matrix in place, and returns whether the matrix is symmetric or skew or neither
/// @param matrix the matrix to be transposed
/// @param size the size of the length and width of the matrix
/// @return 1 if the matrix is symmetrix, 2 if it is skew, and 3 if it is neither
int TransposeMatrix(numeric_t **matrix, numeric_t size);

/// @brief swaps the values pointed to by a and b
/// @param a the first value to be swapped
/// @param b the second value to be swapped 
void swap(numeric_t *a, numeric_t *b);

/// @brief prints a square matrix
/// @param matrix the matrix to be printed
/// @param length the size of the length and width of the matrix
void PrintMatrix(numeric_t **matrix, numeric_t length);
