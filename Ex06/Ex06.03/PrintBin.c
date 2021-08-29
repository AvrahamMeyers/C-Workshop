#include <stdio.h>
#include <malloc.h>
#include "PrintBin.h"

int main(void)
{
    char c = 'A';

    PrintBin(&c, sizeof(c));

    int x = 0x11223344;

    PrintBin(&x, sizeof(x));

    return 0;
}

void PrintBin(BytePointer address, size_t num_bytes)
{
    for (size_t i = 0; i < num_bytes; ++i)
    {
        HexByte* byte = DecToHex(address[i]);

        PrintHexinBin(byte->tens);
        PrintHexinBin(byte->ones);
        printf("\n");
    }    
}  

HexByte* DecToHex(char num)
{
    HexByte* number = (HexByte*)malloc(sizeof(HexByte));

    number->ones = num % HexBase;
    num /= 16;
    number->tens = num % HexBase;

    return number;
}


void PrintHexinBin(short number)
{
    switch (number)
    {
        case 1:
        {
            printf("0001 ");
            break;
        }
        case 2:
        {
            printf("0010 ");
            break;
        }
        case 3:
        {
            printf("0011 ");
            break;
        }
        case 4:
        {
            printf("0100 ");
            break;
        }
        case 5:
        {
            printf("0101 ");
            break;
        }
        case 6:
        {
            printf("0110 ");
            break;
        }
        case 7:
        {
            printf("0111 ");
            break;
        }
        case 8:
        {
            printf("1000 ");
            break;
        }
        case 9:
        {
            printf("1001 ");
            break;
        }
        case 10:
        {
            printf("1010 ");
            break;
        }
        case 11:
        {
            printf("1011 ");
            break;
        }
        case 12:
        {
            printf("1100 ");
            break;
        }
        case 13:
        {
            printf("1101 ");
            break;
        }
        case 14:
        {
            printf("1110 ");
            break;
        }
        case 15:
        {
            printf("1111 ");
            break;
        }
    }
}