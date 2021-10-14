#include <stdlib.h>
#include <debug_macros.h>
#include "hash.h"
#include "nlist.h"

Nlist* htable[HASHSIZE];

Nlist* install(char*, char*);
Nlist* lookup(char* name);
void str_cpy(char* s, char* t);
int str_len(char* str);
int str_cmp(char* s1, char* s2);
char* str_dup(char* str);


int main()
{
    Nlist* np = NULL;

    // 这3个不一定有一个共同的表头（除非他们的hashval是一样的）
    install("NAME", "lyon");
    install("AGE", "26");
    install("HOBBY", "soccer");


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
