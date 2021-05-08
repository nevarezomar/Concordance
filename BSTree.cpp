#include "BSTree.h"

// Default Constructor sets root to nullptr
BSTree::BSTree()
{
	root = nullptr;
}
/* // Default Constructor sets root to nullptr
BSTree::BSTree(string& key)
{
   Node* newRoot = new Node;
   root = newRoot;
   newRoot->keyword = key;
} */

// Destructor uses Empty() to delete BSTree
BSTree::~BSTree()
{
	Empty();
}

// Places a new account into the appropriate place node in the tree according to account number
// Using a helper Insert function defined later.
bool BSTree::Insert(List *nList)
{
	return Insert(nList, root);
}

void BSTree::Display()
{
	Display(root);
}
// Deletes the root of the tree, thus deleting the rest of the tree
void BSTree::Empty()
{
	delete root;
	root = nullptr;
}
// Checks is the root of the tree is empty
bool BSTree::isEmpty() const
{
	if (root == nullptr)
		return true;
	else
		return false;
}
// Helper function for a recursive Display function
void BSTree::Display(Node* cList)
{	
	if (root != nullptr)
	{
		if (cList->left != nullptr)
		{
			Display(cList->left);
		}
		cout << *(cList->pList);
		if (cList->right != nullptr)
		{
			Display(cList->right);
		}
	}
	else
	{
		cout << "There are no accounts." << endl;
	}

}
// Helper function for a recursive Insert function
bool BSTree::Insert(List* nList, Node* cList)
{
   if (cList == nullptr)
   {
      Node *newNode = new Node();
      root = newNode;
      root->pList = nList;
      root->keyword = nList->getKeyword();
      root->left = nullptr;
      root->right = nullptr;
      return true;
   }
	else if(nList->getKeyword() < cList->pList->getKeyword())
	{
		if(cList->left!=nullptr)
			Insert(nList, cList->left);

		else
		{
			Node *newNode = new Node();
			newNode->pList = nList;
			cList->left = newNode;
         newNode->keyword = nList->getKeyword();
			newNode->left=nullptr;
			newNode->right=nullptr;
			return true;
		}  
	}
	else if(nList->getKeyword() > cList->pList->getKeyword())
	{
		if(cList->right!=nullptr)
			Insert(nList, cList->right);

		else
		{
			Node *newNode = new Node();
			newNode->pList = nList;
			cList->right = newNode;
         newNode->keyword = nList->getKeyword();
         newNode->left=nullptr;
			newNode->right=nullptr;
			return true;
		}
	}
	return false;
}
Node* BSTree::Retrieve(const string & target)
{
   if (root== nullptr)
   {
      return nullptr;
   }
   else
   {
      return(Retrieve(target, root));
   }
}
Node* BSTree::Retrieve(const string & target, Node * list)
{
	if (list != nullptr)
		{
			if (target == list->pList->getKeyword())
			{
				return list;
			}
			else if (target > list->pList->getKeyword())
			{
				list = list->right;
            return (Retrieve(target, list));
			}
			else if (target < list->pList->getKeyword())
			{
				list = list->left;
            return (Retrieve(target, list));
         }
		}
   else
   {
      return nullptr;
   }
   return nullptr;
}