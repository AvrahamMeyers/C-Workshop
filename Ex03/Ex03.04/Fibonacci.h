#pragma once

/// @brief shorthand for unigned long long int
typedef unsigned long long int ull_t;

/// @brief calculates and returns the nth fibonacci number
/// @param n index of fibonacci number requested
/// @return returns the nth fibonacci number
ull_t Fibonacci(size_t n);

/// @brief initializes a table for storing fibonacci values
/// @param no parameters
/// @return returns 0 if the initialization was successful, -1 if it was not
int initFibonacci(void);

/// @brief clears the memory used for the fibonacci table
/// @param no parameters
void closeFibonacci(void);
