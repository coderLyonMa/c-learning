#ifndef TNODE
#define TNODE

typedef struct tnode {
    char* word;
    long count;
    struct tnode* left;
    struct tnode* right;
} Tnode;

typedef char* String;
void printtree(Tnode* root);
Tnode* talloc();
Tnode* addtree(Tnode* root, String word);
#endif


