#include <stdio.h>

int main()
{
    float fahr, celc;
    float lower, step, higher;

    fahr = 0;
    lower = 0;
    higher = 300;
    step = 20;
    
    printf("%s\t%s\n", "Fahr", "Celc");
    while (fahr <= higher) {
        celc = 5.0 * (fahr - 32.0) / 9.0;
//        fahr = 32 + 9 / 5 * celc;
        printf("%3.0f %6.1f\n", fahr, celc);
        fahr += step;
    }
}
