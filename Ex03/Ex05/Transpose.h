#pragma once
typedef int numeric_t;

/// @brief transposes a square matrix in place
/// @param matrix the matrix to be transposed
/// @param length the dimension of the length and width of the matrix
void TransposeMatrix(size_t** matrix, numeric_t length);

/// @brief swaps the values of a and b
/// @param a pointer to the first value
/// @param b pointer to the second value
void swap(size_t* a, size_t* b);

/// @brief prints a square matrix 
/// @param matrix the matrix to be printed
/// @param length the length and width of the matrix
void PrintMatrix(size_t** matrix, numeric_t length);