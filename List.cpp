#include "List.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

List::List()
{
    head = nullptr;
}

List::List(string& word)
{
    head = nullptr;
    keyword = word;
}

List::~List()
{
    delete head;
    head = NULL;
}

string List::getKeyword() const
{
    return keyword;
}

void List::setKeyword( const string kword)
{
   keyword = kword;
}

bool List::addNode(queue<string> left, queue<string> right)
{
    Node * newNode = new Node();
    for (int i = 0; i <= 4; i++)
    {
       string leftWord;
       leftWord = left.front();
       left.pop();
       string rightWord;
       rightWord = right.front();
       right.pop();
       if (leftWord != "")
       {
        newNode->leftContext.push(leftWord);
       }
       if (rightWord != "")
       {
        newNode->rightContext.push(rightWord);
       }
    }
    if(head == nullptr)
    {
        head = newNode;
        return true;
    }
    else
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return true;
    }
    return false;

}

void List::displayContext() const
{
   Node* temp = head;
    while (temp != nullptr)
    {
       string beforeOut;
       string afterOut;
        for(int i = 0; i <= 4; i++)
        {
            string word;
            word = temp->leftContext.front();
            beforeOut = beforeOut +" " + word;
            temp->leftContext.pop();
            temp->leftContext.push(word);
        }
        cout << setw(40) << right << beforeOut;
        cout << "| " << keyword << " | ";
        for(int i = 0; i <= 4; i++)
        {
            string word;
            word = temp->rightContext.front();
            afterOut = afterOut + " " + word;
            temp->leftContext.pop();
            temp->leftContext.push(word);
        }
        cout << setw(40) << left << beforeOut;
        cout << endl;
        temp = temp->next;
    }
}

ostream & operator<<(ostream & out, List & list)
{
   List::Node* temp = list.head;
   while (temp != nullptr)
   {
      string beforeOut;
      string afterOut;
      for(int i = 0; i <= 4; i++)
      {
         string word;
         word = temp->leftContext.front();
         beforeOut = beforeOut +" " + word;
         temp->leftContext.pop();
         temp->leftContext.push(word);
      }
      out << setw(35) << left << beforeOut;
      string key = "| " + list.keyword + " |";
      out << setw(10) <<left << key;
      for(int i = 0; i <= 4; i++)
      {
         string word;
         word = temp->rightContext.front();
         afterOut = afterOut + " " + word;
         temp->leftContext.pop();
         temp->leftContext.push(word);
      }
      out << setw(35) << right << beforeOut;
      out << endl;
      temp = temp->next;
   }
	return out;
}