#ifndef DPRINT_MACRO
    #include <stdio.h>
    #define DPRINT_MACRO 1
    #define dprint(expr) printf("<"#expr">" ":\t%d\n", expr)
    #define dprintc(cname) printf(#cname ":\t%c\n", cname)
#endif


int n_strcmp(char* a, char* b);
int strcmp(char* s, char* t);
void swap(char* s[], int i, int j);

