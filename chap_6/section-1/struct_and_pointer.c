#include <debug_macros.h>


int main()
{
    struct foo {
        int len;
        char* str;
    };

    struct foo f, f2, *pf;

    f.len = 20;
    f.str = "abcdef";


    pf = &f;

    printd(*pf++->str); // a
    prints(pf->str);
    printd(f.len);
    prints(f.str);
}

