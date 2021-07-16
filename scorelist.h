#include<bits/stdc++.h> 

#ifndef scorelist_h
#define scorelist_h

class Scorelist {
	int id;
	Scorelist* next;
public:
	Scorelist(int did = -1):id(did) {next = NULL;}
	~Scorelist();
	void insert(int did);
	Scorelist* getnext(){return next;}
	int getid(){return id;}
};

#endif