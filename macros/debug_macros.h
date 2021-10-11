#ifndef DEBUG_MACROS
    #define DEBUG_MACROS
    #include <stdio.h>

    #define printd(expr) printf(#expr ":\t%d\n", expr)
    #define prints(expr) printf(#expr ":\t%s\n", expr)
    
    #define breakpoint(statement) statement; return 0

    #define b_printd(expr) breakpoint(printd(expr))
    #define b_prints(expr) breakpoint(prints(expr))

#endif

