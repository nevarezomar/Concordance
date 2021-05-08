#include <iostream>
#include <string>
#include <queue>
#include "List.h"
#include "BSTree.h"
#include "Concordance.h"

using namespace std;

int main()
{
   string input = "KEY";
   //List* list = new List(input);
   string input2 = "SBEE";
  // List* list2 = new List(input2);
   string input3 = "BEE";
   //List* list3 = new List(input3);
   string input4 = "APPLE";
   //List* list4 = new List(input4);
   queue<string> before;
   queue<string> after;
   before.push("");
   before.push("");
   before.push("HI");
   before.push("HergI");
   before.push("HI");
   after.push("BYE");
   after.push("ergBYE");
   after.push("BYergE");
   after.push("BgerYE");
   after.push("BYE");
   
/*    string left [5] = {"Hi", "bob", "this", "is", "mary"};
   string right [5] = {"Hi", "Mary", "this", "is", "Bob"};
   string left2 [5] = {"New", "Left", "this", "is", "mary"};
   string right2 [5] = {"New", "Right", "this", "is", "Bob"};
   string left3 [5] = {"Hi3", "bob", "this", "is", "mary"};
   string right3 [5] = {"Hi3", "Mary", "this", "is", "Bob"};
   string left4 [5] = {"New3", "Left", "this", "is", "mary"};
   string right4 [5] = {"New3", "Right", "this", "is", "Bob"};
   string left5 [5] = {"Hi4", "bob", "this", "is", "mary"};
   string right5 [5] = {"Hi4", "Mary", "this", "is", "Bob"};
   string left6 [5] = {"New46", "Left", "this", "is", "mary"};
   string right6 [5] = {"New46", "Right", "this", "is", "Bob"};
   string left7 [5] = {"New47", "Left", "this", "is", "mary"};
   string right7 [5] = {"New37", "Right", "this", "is", "Bob"};
   string left8 [5] = {"Hi48", "bob", "this", "is", "mary"};
   string right8 [5] = {"Hi48", "Mary", "this", "is", "Bob"};
   list->addNode(left, right);
   list->addNode(left2, right2);
   list2->addNode(left3, right3);
   list2->addNode(left4, right4);
   list3->addNode(left5, right5);
   list3->addNode(left6, right6);
   list4->addNode(left7, right7);
   list4->addNode(left8, right8);
   list4->addNode(left7, right7);
   list4->addNode(left8, right8);
   list4->addNode(left7, right7);
   list4->addNode(left8, right8);
   list4->addNode(left7, right7);
   list4->addNode(left8, right8);
   list4->addNode(left7, right7);
   list4->addNode(left8, right8);
   list4->addNode(left7, right7);
   list4->addNode(left8, right8); */
   //list->displayContext();
   //list->addNode(before, after);
   //list->displayContext();
   //cout << *list;
   BSTree tree;
   //tree.Insert(list);
  // tree.Insert(list2);
   //tree.Insert(list3);
   //tree.Insert(list4);
   //tree.Display();

   //cout << tree.Retrieve(input4);

  

   Concordance concor;
   concor.Enqueue("corpus.txt");
   concor.Display();


   return 0;
}