#pragma once
#include<queue>
#include"BSTree.h"
#include"List.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class Concordance
{
public:
	Concordance();
	~Concordance();
	bool Enqueue(const string corpusFile);
   
	void Dequeue();
	void Display();
	
private:
	queue<string> corpus;
   queue<string> beforeCon;
	BSTree concor;
   bool CleanUp(const string corpusFile);

};