#include<bits/stdc++.h>
#include "scorelist.h"
#ifndef listnode_H
#define listnode_H
class listnode{
    
    listnode *next;
    int id;
    int times;
    public:
        listnode(int did):id(did),times(0){next = NULL;}
        ~listnode();
        int volume();
        void add(int did);
        int search(int did);
        void passdocuments(Scorelist* scorelist );
};

#endif