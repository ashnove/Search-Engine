#include "search.h"

void search(char* token, Trienode* trie, Mymap *map, int k){
    cout << "search Not implemeneted yet" << endl;

}

void df(Trienode* trie){
    cout << "df No no" << endl;

}

int tf(char* token, Trienode* trie){
    char* token2;
    token2 = strtok(NULL, " \t\n");
    if(token2 == NULL){
            free(token2);
            return -1;
    }
    for(int l = 0; l < strlen(token2); l++){
        if(!isdigit(token2[l])){
            token2 = NULL;
            free(token2);
            return -1;
        }
    }
    int id = atoi(token2);
    token2 = strtok(NULL, " \t\n");
    if(token2 == NULL){
        free(token2);
        return -1;
    }
    cout << "tf ok" << endl;
    return 1;
}