#include <stdio.h>
#include <malloc.h>
#include "fibonacci.h"
#pragma once


int main(void)
{
    printf("Enter a number:\n");

    size_t *number_entry = malloc(sizeof(ull_t));

    scanf_s("%d", number_entry);

    for (size_t i = 0; i <= *number_entry; i++)
    {
        printf("%llu ", Fibonacci(i));
    }

    free(number_entry);

    return 0;
}