#include <debug_macros.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
    struct nlist* next;
    char* name;
    char* defn;
};

#define HASHSIZE 101

struct nlist* hashtable[HASHSIZE];

struct nlist* lookup(char* name);
struct nlist* install(char* name, char* defn);
unsigned hash(char* s);
int str_cmp(char* s1, char* s2);


int main()
{
    struct nlist* p;
    p = lookup("FOO");

    
//    printptr(p->name);

    p = install("NAME", "lyon");
    p = lookup("NAME");
        install("AGE", "26");
    prints(p->defn);
        p = lookup("AGE");
        prints(p->defn);
        p = lookup("NAME");
        prints(p->defn);
}


struct nlist* lookup(char* name)
{
    struct nlist* p;
    unsigned hashval = hash(name);
    
    for (p = hashtable[hashval]; p != NULL; p = p->next)
        if (str_cmp(name, p->name) == 0)
            return p;

    return NULL;
}


struct nlist* install(char* name, char* defn)
{
    struct nlist* p;
    unsigned hashval;

    p = lookup(name);
    
    if (p == NULL) {
        p = malloc(sizeof(struct nlist));
        p->name = strdup(name);
        p->defn = strdup(defn);
        
        if (p == NULL || p->name == NULL || p->defn == NULL)
            return NULL;

        hashval = hash(name);
        hashtable[hashval] = p;

        strcpy(p->name, name);
        strcpy(p->defn, defn);
        return p;
    } else {
        free((void*) p->defn);
        if ((p->defn = strdup(defn)) != NULL) {
            return p;
        }
        return NULL;
    }
}


unsigned hash(char* s)
{
    unsigned hashval;

    for (hashval = 0U; *s; ++s) {
        hashval = *s + hashval * 31;
    }

    return hashval % HASHSIZE;
}

int str_cmp(char* s1, char* s2)
{
    for (; *s1 && *s2 && *s1 == *s2; ++s1, ++s2)
        ;
    return *s1 - *s2;
}

