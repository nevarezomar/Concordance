#pragma once

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

struct Node // Account nodes in the tree
{
	Node* left = NULL;
	Node* right = NULL;
	string keyword;
	List *pList;
};

class BSTree
{
public:
	BSTree();	// Default Constructor
   BSTree(string& keyword);	// Default Constructor
	~BSTree();	// Destructor

	bool Insert(List* insert);	// Inserted a new account node into the tree
	void Display(); // Prints the contents of the tree
   Node* Retrieve(const string &);	// Find a specific account node in the tree

	void Empty(); // Clears the contents of the tree
	bool isEmpty() const;	// Checks to see if the tree is empty

private:
	Node* root; // root node
	bool Insert(List *, Node *); // Helper function for Insert
   Node* Retrieve(const string&, Node*);
	void Display(Node *);			// Helper function for Display
};