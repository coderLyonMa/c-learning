#include <unistd.h>
#include <stdlib.h>
#include <debug_macros.h>

#ifdef FOO
#define BAR 1
#else
#define BAR -1
#endif

int main()
{
    unsigned char c;
    int i;
    char* sp;
    
    printf("%d", BAR);

    return 0;
    sp = malloc(100);
    getcwd(sp, 100);
    prints(sp);
    return 0;
}
