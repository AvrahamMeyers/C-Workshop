#include <stdio.h>
#include <malloc.h>
#include "Fibonacci.h"

static ull_t *fibonacci_table = NULL;
static size_t fibonacci_table_size = 0;

ull_t Fibonacci(size_t n)
{
    size_t previous_size = fibonacci_table_size;

    if (fibonacci_table == NULL)
    {
        initFibonacci();
    }

    if (n >= fibonacci_table_size)
    {
        fibonacci_table_size = n + 1;
        fibonacci_table = (ull_t *)realloc(fibonacci_table, fibonacci_table_size * sizeof(ull_t));

        for (size_t index = previous_size; index < fibonacci_table_size; ++index)
        {
            fibonacci_table[index] = fibonacci_table[index - 1] + fibonacci_table[index - 2 ];
        }
    }

    return fibonacci_table[n];
}

int initFibonacci(void)
{
    if (fibonacci_table != NULL)
    {
        return 0;
    }

    fibonacci_table_size = 2;

    fibonacci_table = malloc(fibonacci_table_size * sizeof(ull_t));

    if (fibonacci_table == NULL)
    {
        return -1;
    }

    *fibonacci_table = 0;
    *(fibonacci_table + 1) = 1;

    return 0;
}

void closeFibonacci(void)
{
    if (fibonacci_table == NULL)
    {
        return;
    }

    free(fibonacci_table);
    fibonacci_table = NULL;
}