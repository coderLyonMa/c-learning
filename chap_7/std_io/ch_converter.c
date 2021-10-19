#include <debug_macros.h>
#include <string.h>
#include <ctype.h>
#define LOWER_FLAG "lower"
#define UPPER_FLAG "upper"


int main(int argc, char** argv)
{
    int c, lower, upper;
    lower = upper = 0;

    if (strstr(argv[0], LOWER_FLAG) != NULL)
        lower = 1;
    else if (strstr(argv[0], UPPER_FLAG) != NULL)
        upper = 1;
    else {
        printf("[ERROR]: invalid option argv[0]: %s\n", argv[0]);
        return 0;
    }

    while ((c = getchar()) != EOF)
        if (lower)
            putchar(tolower(c));
        else
            putchar(toupper(c));

    return 0;
}
