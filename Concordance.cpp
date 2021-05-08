#include "Concordance.h"
#include "List.h"
#include "BSTree.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include<string>
#include <algorithm>


Concordance::Concordance()
{
}
Concordance::~Concordance()
{
}
bool Concordance::CleanUp(const string corpusFile)
{
   ifstream in(corpusFile);
   ofstream cleanCorpus("clean.txt");
   string word;
	if (!in)
	{
		cout << "File NOT Opened!" << endl;
      return false;
	}
	while (in >> word)
	{
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); } ), word.end());
      if(word != "")
      {
         cleanCorpus << word << endl;
      }
   }
   return true;
}

bool Concordance::Enqueue(const string corpusFile)
{
   CleanUp(corpusFile);
   ifstream in("clean.txt");
   ifstream temp("clean.txt");
   string keyword;
   string word;
   
	if (!in)
	{
		cout << "File NOT Opened!" << endl;
      return false;
	}
   else
   {
      for(int i = 0; i <= 5; i++)
      {
         getline(in, word);
         corpus.push(word);
      }
      for(int i = 0; i <= 4; i++)
      {
         beforeCon.push("");
     }
   }
	while (!in.eof())
	{
      keyword = corpus.front();
		if (keyword.empty())
		{
			break;
		}
		else 
      {
         if (concor.Retrieve(keyword) == nullptr)
            {
               List* list = new List(keyword);
               string temp = corpus.front();
               corpus.pop();
               list->addNode(beforeCon, corpus);
               concor.Insert(list);
               corpus.push(temp);
               for (int i = 0; i < corpus.size() - 1; i++)
               {
                  string word = corpus.front();
                  corpus.pop();
                  corpus.push(word);
               }
               //cout << *(list) << endl;
            }
         else
         {
            string temp = corpus.front();
            corpus.pop();
            concor.Retrieve(keyword)->pList->addNode(beforeCon, corpus);
            corpus.push(temp);
            for (int i = 0; i < corpus.size() - 1; i++)
            {
               string word = corpus.front();
               corpus.pop();
               corpus.push(word);
            }
         }
      string temps = corpus.front();
      beforeCon.pop();
      beforeCon.push(temps);
      corpus.pop();
      getline(in, word);
      corpus.push(word);
      }

   }
   return true;

}

void Concordance::Display()
{
   concor.Display();
}