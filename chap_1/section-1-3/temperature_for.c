#include <stdio.h>

int main()
{
    for (float fahr = 300.0; fahr >= 0; fahr -= 20) {
        printf("%3.f %3.1f \n", fahr, (fahr - 32) * 5.0 / 9.0);
    }
}
