#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(int argc, char** argv, char** envp)
{
    for (char** env = envp; *env != 0; env++)
    {
        char* thisEnv = *env;

        char* tokens;
        char* context;
        tokens = strtok_s(thisEnv, "=", &context);
        printf("Environment variable \"%s\" has the value ", tokens);
        while (tokens)
        {
            tokens = strtok_s(NULL, "=", &context);
            if (tokens)
            {
                printf("%s.\n", tokens);
            }
        }
    }
    return 0;
}


