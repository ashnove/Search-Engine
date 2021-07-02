#include<bits/stdc++.h>

#ifndef listnode_H
#define listnode_H
class listnode{
    
    listnode *next;
    int id;
    int times;
    public:
        listnode(int did):id(did),times(0){next = NULL;}
        ~listnode();
        void add(int did);
};

#endif