#include <stdio.h>


int main()
{
    char s[] = "我";
    for (int i = 0; s[i] != '\0'; i++)
        printf("%x\n", ((char) s[i] & 0xFF));
}
