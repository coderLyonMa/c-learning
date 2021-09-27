#ifndef DPRINT_MACRO
    #include <stdio.h>
    #define DPRINT_MACRO 1
    #define dprint(expr) printf("<" "expression:" #expr">" "value: %d\n", expr)
    #define dprintc(cname) printf(#cname ":\t%c\n", cname)
    #define mysprint(str_p) printf("<"#str_p">" ":\t%s\n", str_p)
#endif


int str_len(char *s);
int strcmp(char* a, char* b);
int n_strcmp(char* a, char* b);
void str_cat(char* s, char* t);
int str_end(char* s, char* t);

void str_ncp(char* s, int n, char* t);
int str_ncmp(char* s, int n, char* t);
void str_ncat(char* s, int n, char* t);

