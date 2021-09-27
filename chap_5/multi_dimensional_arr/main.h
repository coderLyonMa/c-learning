#ifndef DPRINT_MACRO
    #include <stdio.h>
    #define DPRINT_MACRO 1
    #define dprint(expr) printf("<" "expression:" #expr">" "value: %d\n", expr)
    #define dprintc(cname) printf(#cname ":\t%c\n", cname)
    #define mysprint(str_p) printf("<"#str_p">" ":\t%s\n", str_p)
#endif

