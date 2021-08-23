#include <stdio.h>
#include <malloc.h>
#include "Fibonacci.h"

int main()
{
    for (size_t numeric_t = 0; numeric_t <= 100; ++numeric_t)
    {
        printf("%llu ", Fibonacci(numeric_t));

        if (numeric_t > 93)
        {
            return 0;
        }
    }
    return 0;
} 