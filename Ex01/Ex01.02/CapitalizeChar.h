#pragma once

/// @brief capitalizes the given letter
/// @param c input char
/// @return capitalized char
char CapitalizeChar(char c)
{
    if (c >= 'a')
    {
        c = c - ('a' - 'A');
    }

    return c;
}