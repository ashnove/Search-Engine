#include "engine.h"
using namespace std;

int inputmanager(char* input, Trienode* trie, Mymap* map, int k){
    char* token = strtok(input, " \t\n");
    if(!strcmp(token,"/search"))
        search(token, trie, map,k);
    else if(!strcmp(token, "/df")){
        df(trie);
    }
    else if(!strcmp(token, "/tf")){
        if(tf(token, trie) == -1){
            return -1;

        }
    }
    else if(!strcmp(token, "/exit")){
        cout << "Exiting..." << endl;
        token = NULL;
        free(token);
        return 2;
    }
    else return -1;
    token = NULL;
    free(token);
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 5 || strcmp(argv[1],"-d") || strcmp(argv[3],"-k"))
    {
        cout << "invalid arguments" << endl;
        return -1;
    }
    cout << "Please Wait" << endl;
    int lineCounter = 0;
    int maxLength = -1;
    int k = atoi(argv[4]);

    if(read_sizes(&lineCounter,&maxLength,argv[2])==-1)
        return -1;

    Mymap *mymap = new Mymap(lineCounter, maxLength);
    Trienode *trie = new Trienode();


    if(read_input(mymap, trie, argv[2])== -1){
        delete mymap;
        return -1;
    }
    cout<<"Database Ready"<<endl;
    
    // for(int i = 0; i < mymap->getsize(); i++)
    //     mymap->print(i);
    
    char* input=NULL;
    size_t inputlength=0;
    while(1){
        getline(&input, &inputlength,stdin);
        int ret = inputmanager(input, trie, mymap, k);
        if(ret == -1){
            cout << "Invalid input" << endl;
        }
        else if(ret == 2){
            free(input);
            break;
        }
        free(input);
        inputlength = 0;
    }
    
    // cout<<"Linecounter: "<<lineCounter<<endl<<"Maxlength: "<<maxLength<<endl;
    delete(mymap);
    delete(trie);
    return 1;
}