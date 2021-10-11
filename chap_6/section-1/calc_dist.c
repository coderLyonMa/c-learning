#include <math.h>
#include <debug_macros.h>
#include "point.h"

double calc_dist(struct point a, struct point b);

int main()
{
    struct point a = {1.5, 1.5,};
    struct point b = {2.5, 2.5,};
    
    double dist = calc_dist(a, b);
    printf("distance from a to b is %g\n", dist);
}

double calc_dist(struct point a, struct point b)
{

    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

