#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv)
{
    for (size_t i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    printf("the number of command line arguments is: %d\n", argc);

    size_t switch_counter = 0;
    size_t uppercase_counter = 0;
    size_t lowercase_counter = 0;

    for (size_t i = 1; i < argc; ++i)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            ++switch_counter;
        }
        else 
        {
            bool upper = true, lower = true;

            for (char *letter = argv[i]; *letter != '\0'; ++letter)
            {
                if (*letter < 'a' || *letter > 'z')
                {
                    lower = false;
                }
                if (*letter < 'A' || *letter > 'Z')
                {
                    upper = false;
                }
            }
            if (upper)
            {
                ++uppercase_counter;
            }
            else if (lower)
            {
                ++lowercase_counter;
            }
        }
    }

    printf("the number of switches is: %d\n", switch_counter);
    
    printf("the number of uppercase commands is: %d\n", uppercase_counter);

    printf("the number of lowercase commands is: %d\n", lowercase_counter);

    printf("the number of commands that are neither uppercase nor lowercase is: %d\n", 
        argc - lowercase_counter - uppercase_counter - switch_counter);

}