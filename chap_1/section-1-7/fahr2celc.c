#include <stdio.h>
#define FLOOR  0
#define STEP   5
#define CEIL   100


float fahr2celc(int fahr);


int main()
{
    for (int fahr = FLOOR; fahr <= CEIL; fahr += STEP)
        printf("fahrenheit: %d\t celcius: %4.2f\n", fahr, fahr2celc(fahr));
}

float fahr2celc(int fahr)
{
    return (fahr - 32) / 1.8;
}
