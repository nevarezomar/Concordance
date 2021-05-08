#pragma once

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class List
{
   // Overloaded ostream to print out accounts
	friend ostream& operator << (ostream &out, List &list);

public:
   List();
   List(string& keyword);
   ~List();

   bool addNode(queue<string> left, queue<string> right);
   void displayContext() const;
   string getKeyword() const;
   void setKeyword(const string keyword);

private:
   struct Node // Nodes in the List
	{
		Node* next = nullptr;
		queue<string> leftContext;
      queue<string> rightContext;
	};
   string keyword;
	Node* head; // Head node

};