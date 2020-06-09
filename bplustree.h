#define BPLUSTREE_H

#define MAX 100
#define NULL 0

#include <book.h>

class Node
{
    bool IS_LEAF;
    int *key, size;
    Node** ptr;
    friend class BPTree;
public:
    Node()
    {
        key = new int[MAX];
        ptr = new Node*[MAX+1];
    }
};



class BPTree
{
    Node *root;
public:
    BPTree();
    void search(Book);
};

