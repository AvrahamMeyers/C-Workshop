#pragma once

/// @brief 
#define HexBase 16


typedef unsigned char* BytePointer;

/// @brief 
/// @param address 
/// @param num_bytes 
void PrintBin(BytePointer address, size_t num_bytes);

typedef struct HexByte_t
{
    short tens;
    short ones;

} HexByte;

HexByte *DecToHex(char num);

void PrintHexinBin(short number);