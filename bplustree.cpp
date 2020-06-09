#include "bplustree.h"

BPTree::BPTree()
{
    root = NULL;
}

void BPTree::search(Book x)
{
    if (root != NULL)
    {
        Node* cursor = root;
        while(cursor->IS_LEAF == false)
        {
            for(int i = 0; i < cursor->size; i++)
            {
                if(x.getYear() < cursor->key[i])
                {
                    cursor = cursor->ptr[i];
                    break;
                }
                if(i == cursor->size - 1)
                {
                    cursor = cursor->ptr[i+1];
                    break;
                }
            }
        }

        for(int i = 0; i < cursor->size; i++)
        {
            if(cursor->key[i] == x.getYear())
            {
                return;
            }
        }
    }
}
