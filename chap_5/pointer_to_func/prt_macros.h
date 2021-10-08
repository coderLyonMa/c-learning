#ifndef PRT_MACROS
#define PRT_MACROS
    #define dprint(expr) printf(#expr ":\t%d\n", expr)
    #define sprint(expr) printf(#expr ":\t%s\n", expr)
    #define cprint(expr) printf(#expr ":\t%c\n", expr)
    #define cancel if (0)
#endif    

