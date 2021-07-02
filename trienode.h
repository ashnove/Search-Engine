#include<bits/stdc++.h>
#include "listnode.h"
#ifndef TRIENODE_H
#define TRIENODE_H
using namespace std;

class Trienode {
    Trienode *sibling;
    Trienode* child;
    //listnode* list;
    char value;
    public:
        Trienode();
        ~Trienode();
        void insert(char* token, int id);
};

#endif