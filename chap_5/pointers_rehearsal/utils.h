#ifndef DPRINT_MACRO
    #include <stdio.h>
    #define DPRINT_MACRO 1
    #define dprint(expr) printf("<" "expression:" #expr">" "value: %d\n", expr)
    #define dprintc(cname) printf(#cname ":\t%c\n", cname)
    #define mysprint(str_p) printf("<"#str_p">" ":\t%s\n", str_p)
#endif

int get_line(char* line, int max);
void reverse(char* s);
int strindex(char* s, char* t);
int atoi(char *s);
void itoa(int i, char* s);
int str_ncmp(char* s, int n, char* t);

