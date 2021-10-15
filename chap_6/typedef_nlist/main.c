#include <stdlib.h>
#include <debug_macros.h>
#include "hash.h"
#include "nlist.h"

Nlist* htable[HASHSIZE];

Nlist* install(char*, char*);
Nlist* lookup(char* name);
Nlist* undef(char*);

void str_cpy(char* s, char* t);
int str_len(char* str);
int str_cmp(char* s1, char* s2);
char* str_dup(char* str);

struct kv {
    char* name;
    char*defn;
} kv_arr[] = {
    {"NAME", "foo"},
    {"AGE", "100" },
    {"HOBBY", "make money" },
    {"TEMP", "cool" },
    {"NLIST", "NLIST" },
};

#define NKV (sizeof kv_arr / sizeof(struct kv))

int main()
{
    Nlist* np;

    for (int i = 0; i < NKV; ++i)
        install(kv_arr[i].name, kv_arr[i].defn);

    prints(lookup(kv_arr[2].name)->defn);
    undef(kv_arr[2].name);
    printptr(lookup(kv_arr[2].name));
    return 0;
}

Nlist* lookup(char* name)
{
    Nlist* p;

    for (p = htable[hash(name)]; p != NULL; p = p->next)
        if (str_cmp(p->name, name) == 0)
            return p;

    return NULL;
}

Nlist* install(char* name, char* defn)
{
    Nlist* p;
    unsigned hval = hash(name);

    if ((p = lookup(name)) == NULL) {
        p = (Nlist*) malloc(sizeof(Nlist));
        if (p == NULL || (p->name = str_dup(name)) == NULL)
            return NULL;
        hval = hash(name);
        p->next = htable[hval];
        htable[hval] = p;
    } else {
        free((char*) p->defn);
    }

    if ((p->defn = str_dup(defn)) == NULL)
        return NULL;

    return p;
}

Nlist* undef(char* name)
{
    Nlist *head, *p, *target_p;
    Nlist *former_p;
    target_p = NULL;

    if ((p = lookup(name)) == NULL)
        return NULL;

    for (former_p = NULL; former_p; former_p = former_p->next)
        if (former_p->next == p) {
            former_p->next = p->next;
            free((Nlist*) p);
            return former_p;
        }

    free((Nlist*) p);
    return NULL;
}


void str_cpy(char* s, char* t)
{
    while (*s++ = *t++)
        ;
}

int str_len(char* str)
{
    char* s = str;
    while (*s)
        ++s;
    return s - str;
}

int str_cmp(char* s1, char* s2)
{
    for (; *s1 && *s2 && *s1 == *s2; ++s1, ++s2)
        ;
    return *s1 - *s2;
}

char* str_dup(char* str)
{
    char* p;
    if ((p = (char*) malloc(str_len(str))) != NULL) {
        str_cpy(p, str);
        return p;
    }
    return NULL;
}
