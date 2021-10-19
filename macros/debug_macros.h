#ifndef DEBUG_MACROS
    #define DEBUG_MACROS
    #include <stdio.h>

    #define printd(expr) printf(#expr ":\t%d\n", expr)
    #define prints(expr) printf(#expr ":\t%s\n", expr)
    #define printfl(expr) printf(#expr ":\t%g\n", expr)
    #define printptr(expr) printf(#expr ":\t%p\n", expr)
    
    #define breakpoint(statement) statement; return 0

    #define b_printd(expr) breakpoint(printd(expr))
    #define b_prints(expr) breakpoint(prints(expr))

    #define prt_and_exec(statement) printf("%s;\n", #statement); statement

    #define CANCEL if (0)
#endif

