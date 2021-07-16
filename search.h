#include<bits/stdc++.h>
#include "trienode.h"
#include "Map.h"
#include "scorelist.h"
#include "maxheap.h"
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;
void search(char* token, Trienode* trie, Mymap* map, int k);
void df(Trienode* trie);
int tf(char* token, Trienode* trie);
