#include <stdio.h>
#define STEP   3
#define FLOOR  0
#define CEIL   100

float celc2fahr(int celc);

int main()
{
    for (int celc = FLOOR; celc <= CEIL; celc += STEP)
        printf("celcius: %d\t fahrenheit: %5.1f\n", celc, celc2fahr(celc));
}

float celc2fahr(int celc)
{
    return celc * 1.8 + 32;
}

