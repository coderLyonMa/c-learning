#include "hash.h"


typedef char* String;


unsigned hash(String s)
{
    unsigned hashval;
    for (hashval = 0; *s; ++s)
        hashval = hashval * 31 + *s;
    return hashval % HASHSIZE;
}


