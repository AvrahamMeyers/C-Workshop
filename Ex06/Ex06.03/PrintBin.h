#pragma once

/// @brief macro for base 16
#define HexBase 16

/// @brief pointer to a single byte
typedef unsigned char* BytePointer;

/// @brief prints the sequence of bytes pointed to address in binary
/// @param address the address of the sequence of bytes
/// @param num_bytes the number of bytes in the sequence
void PrintBin(BytePointer address, size_t num_bytes);

/// @brief a struct for storing the two digits in hexadecimal for a byte
typedef struct HexByte_t
{
    short tens;
    short ones;

} HexByte;

/// @brief receives a decimal number and returns a HexByte with the corresponding hexadecimal digits
/// @param num the number to convert to hexadecimal
/// @return the HexByte with the corresponding hexadecimal values
HexByte *DecToHex(char num);

/// @brief takes a number between 1-15 and prints its binary form
/// @param number the number to print in binary
void PrintHexinBin(short number);