#include <stdio.h>
#include "fibonacci.h"

ull_t Fibonacci(size_t n)
{
    if (n < 0)
    {
        return -1;
    }

    if (n <= 1)
    {
        return n;
    }

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}