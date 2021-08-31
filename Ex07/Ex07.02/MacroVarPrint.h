#ifndef _MACRO_VAR_PRINT_H_
#define _MACRO_VAR_PRINT_H_

#include <stdio.h>
/*
 * @file macro variable print
 */

/*
 * @brief a macro for printing a variable and its value in debug mode
 * to trace it
 */
    #ifdef _DEBUG
        #define TRACE_VAR(x, stringformat) printf("%s = " stringformat "\n", #x, x)

    #else
        #define TRACE_VAR(x)
    #endif

#endif