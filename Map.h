#include<bits/stdc++.h>

#ifndef MAP_H
#define MAP_H
using namespace std;

class Mymap{
    int size; // number of documents
    int buffersize; 
    char** documents;
    int* lengths;
    public:
    Mymap(int size, int buffersize);
    ~Mymap();
    int insert(char* line,int i);
    void setlength(int id,int length){lengths[id]=length;}
    int getlength(int id){return lengths[id];}
    void print(int i){cout<<i<<" "<<documents[i]<<endl;}
    char* getDocument(int i){return documents[i];}
    const int getsize(){return size;}
    const int getbuffersize(){return buffersize;}
};
#endif