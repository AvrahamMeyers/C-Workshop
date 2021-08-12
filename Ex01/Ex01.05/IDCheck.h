#pragma once
#include <stdbool.h>

/// @brief the number of digits in an ID 
const int IDLENGTH = 9;

/// @brief Checks if given ID is a valid ID 
/// @param ID ID to be checkec
/// @return true if the ID is valid, false if it is not
bool IDCheck(int ID)
{
    int sum_of_digits = 0;
    for (int index = 0; index < IDLENGTH; index++)
    {
        int digit = ID % 10;

        if (index % 2 == 0)
        {
            sum_of_digits += digit;
        }
        else
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }

            sum_of_digits += digit;
        }

        ID /= 10;
    }

    int return_value = sum_of_digits % 10;

    return return_value == 0;
}