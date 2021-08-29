#pragma once

/// @brief a pointer to a single byte
typedef unsigned char* BytePointer;

/// @brief takes a pointer to a sequence of bytes, and the number of bytes, and 
/// prints each bytes values in hexadecimal
/// @param address a pointer to the first byte in the sequence
/// @param num_bytes the number of bytes in the sequence
void PrintHex(BytePointer address, size_t num_bytes);