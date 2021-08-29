#include <stdio.h>
#include "PrintHex.h"

int main(void)
{
    char c = 'A';

    PrintHex(&c, sizeof(c));

    int x = 0x11223344;

    PrintHex(&x, sizeof(x));

    return 0;
}

void PrintHex(BytePointer address, size_t num_bytes)
{
    for (size_t i = 0; i < num_bytes; ++i)
    {
        printf("%X\n", address[i]);
         
    }
}