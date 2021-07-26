#include<bits/stdc++.h>
#include "listnode.h"
#include "scorelist.h"
#ifndef TRIENODE_H
#define TRIENODE_H
using namespace std;

class Trienode {
    bool isLast;
    Trienode* child[256];
    listnode* list;
    public:
        Trienode();
        ~Trienode();
        void insert(char* token, int id);
        int tfsearchword(int id, char* word, int curr);
        int dsearchword(char* word,int curr);
        void dsearchall(char* buffer,int curr);
        void search(char *word, int curr, Scorelist *scorelist);
};

#endif