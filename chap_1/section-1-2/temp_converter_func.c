#include <stdio.h>

float celc2fahr(int celc);

int main()
{
    printf("Celcius\tFahrenheit\n");
    for (int i = 0; i <= 100; i += 2)
        printf("%d\t%4.1f\n", i, celc2fahr(i));
}

float celc2fahr(int celc)
{
    return celc * (9.0 / 5.0) + 32;
}
