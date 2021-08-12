#pragma once

const int IDLENGTH = 8;

/// @brief returns the 9th digit for the given ID to make it a valid 9 digit ID
/// @param ID 8 digit ID to 
/// @return 9th digit of the ID
int CheckDigit(int ID)
{
    int sum_of_digits = 0;

    for (int index = 1; index <= IDLENGTH; index++)
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

    int ones_place = sum_of_digits % 10;
    int check_digit = (10 - ones_place) % 10;

    return check_digit;

}