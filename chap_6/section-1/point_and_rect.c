#include <debug_macros.h>
#include "point.h"
#include "rect.h"

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

struct point make_point(double x, double y);
struct point add_point(struct point, struct point);
int point_in_rect(struct point pt, struct rect r);
struct rect canonrect(struct rect r);

int main()
{
    struct point pt1, pt2, new_pt;

    pt1 = make_point(1.5, 2.5);
    pt2 = make_point(3.5, 5.5);
    
    new_pt = add_point(pt1, pt2);

    printfl(new_pt.x);
    printfl(new_pt.y);
    
    struct point p3 = {1.5, 2.49999999999,};
    struct rect r = {pt1, pt2};
    
    struct rect ur = {
        {3.6, 5.8},
        {1.7, 8.5},
    };

    printfl(ur.pt1.x);
    printfl(ur.pt1.y);
    printfl(ur.pt2.x);
    printfl(ur.pt2.y);
    
    ur = canonrect(ur);
    printfl(ur.pt1.x);
    printfl(ur.pt1.y);
    printfl(ur.pt2.x);
    printfl(ur.pt2.y);    
}

struct point make_point(double x, double y)
{
    struct point tmp;
    tmp.x = x;
    tmp.y = y;

    return tmp;
}

struct point add_point(struct point pt1, struct point pt2)
{
    // there is no need for tmp dcl, since struct is passed by its value
    pt1.x += pt2.x;
    pt1.y += pt2.y;

    return pt1;
}

int point_in_rect(struct point pt, struct rect r)
{
    return pt.x >= r.pt1.x && pt.x < r.pt2.x && \
        pt.y >= r.pt1.y && pt.y < r.pt2.y;
}

struct rect canonrect(struct rect r)
{
    struct rect tmp;

    tmp.pt1.x = min(r.pt1.x, r.pt2.x);
    tmp.pt1.y = min(r.pt1.y, r.pt2.y);
    tmp.pt2.x = max(r.pt1.x, r.pt2.x);
    tmp.pt2.y = max(r.pt1.y, r.pt2.y);
    
    return tmp;
}

