#include <stdio.h>
#include <string.h>

int main(int argc, char** argv, char** envp)
{
    char* search_string = argv[1];

    for (char** env = envp; *env != 0; env++)
    {
        char* thisEnv = *env;

        char* starting_index = strstr(thisEnv, search_string);

        if (starting_index == thisEnv)
        {
            printf("%s\n", thisEnv);
        }
    }
    return 0;
}