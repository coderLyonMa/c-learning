#include <debug_macros.h>

struct perms {
    unsigned char owner_perms: 3;
    unsigned char group_perms: 3;
    unsigned char othrs_perms: 3;
};


int main()
{
    struct perms p;
    p.owner_perms = 07;
    p.group_perms = 05;
    printd(p.owner_perms);
    return 0;
}

