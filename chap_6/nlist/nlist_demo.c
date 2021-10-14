#include <stdlib.h>
#include <debug_macros.h>

struct nlist {
    struct nlist* next;
    char* name;
    char* defn;
};

int main()
{
    struct nlist *a, *b;

    a = (struct nlist*) malloc(sizeof(struct nlist));
    b = (struct nlist*) malloc(sizeof(struct nlist));

    char* a_name = "NAMEA";
    char* b_name = "NAMEB";
    char* a_defn = "DEFNA";
    char* b_defn = "DEFNB";

    printptr(a->next);

    prints(a->name);
    a->name = a_name;
    prints(a->name);
    a->next = b;
    printptr(a->next);

    prints(b->name);
    b->name = b_name;
    prints(a->next->name);
}

