#include <debug_macros.h>

#define print_point(point) \
    printf("Info of point [" #point "]:\n"); \
    printf("x value: %d\n", point.x); \
    printf("y value: %d\n", point.y);

#define print_rect(rect) { \
    printf("Info of rect " #rect "\n"); \
    print_point(rect.a); \
    print_point(rect.b); }

#define printp(pointer) printf(#pointer " points to %p\n", pointer)

int main()
{
    // define a data type named point
    // this type is a set of several data type which might be different with each other
    // below dcl define a template of a new data type without new mem space
    struct point {
        int x;
        int y;
    };

    // define a variable with type: point, and assign it with initialized value
    struct point pt = {5, 6};
    // it can be declared without init val
    struct point pt_2;

    // struct is nestable
    struct rect {
        struct point a;
        struct point b;
    };

    struct point a = {0, 0};
    struct point b = {1, 1};
    
    print_point(a);

    struct rect r = {a, b};
    struct rect r_2 = {{1, 1}, {2, 2}};
    struct rect r_3 = {5, 5, 6, 6};

    print_rect(r);

    // following lines show that struct is based on array, since x and y are consistent in mem
    printp(&a.x);
    printp(&a.y);
    
    struct person {
        int age;
        char name[20];
        double salary;
    };
    
    struct person p = {
        33,
        "Lionel Messi",
        200.0 * 1000.0 * 1000.0,
    };

    // following lines show that struct is based on array, since x and y are consistent in mem
    printp(&p.age); // 0x7fff04a01310
    printp(&p.name); // 0x7fff04a01314
    printp(&p.salary); // 0x7fff04a01328
}

