#include "trienode.h"

Trienode::Trienode():value(-1)
{
    sibling = NULL;
    child = NULL;
    //list = NULL;
}
Trienode::~Trienode()
{
    // if(list!=NULL)
    //     delete(list);
    if(child != NULL)
        delete child;
    if(sibling != NULL)
        delete sibling;
    
}

void Trienode::insert(char* token, int id){
    if(value == -1 || value == token[0]){
        value = token[0];
        if(strlen(token) == 1){
            //initilize list
        }
        else{
            if(child == NULL){
                child = new Trienode();
            }
            child->insert(token + 1,id);
        }
    }
    else{
        if(sibling == NULL){
            sibling = new Trienode();
        }
        sibling->insert(token, id);
    }
    return;
}