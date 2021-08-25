#pragma once

typedef struct Dog_t
{
    char* name;
    float weight;
} Dog;

/// @brief sorts an array of dogs according to the sort parameter, either the name or the weight
/// @param kennel an array of dogs
/// @param sort_parameter a string representing the parameter to sort by, either the name or the weight
void SortDogs(Dog kennel[], size_t size, char* sort_parameter);

/// @brief swaps the location of the two dogs that are entered
/// @param A the first dog to be swapped 
/// @param B the second dog to be swapped
void SwapDogs(Dog* A, Dog* B);

/// @brief prints the array of dogs 
/// @param kennel the array of dogs
/// @param size the length of the array
void PrintDogs(Dog kennel[], size_t size);
