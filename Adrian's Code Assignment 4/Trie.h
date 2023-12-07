#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Trie
{
public:
	string search(string query);
	void buildTrie();
	long test;
	void dictTest();
	~Trie();
private:
	string path = "bigDictionary.txt";
	void buildSubtree(Node* newRoot, string word, int levelCount);
	string searchNodes(Node* newRoot, string query, int levelCount);
	Node* root = new Node;
};//class

void Trie::buildTrie()//only top node handled internally
{
	fstream strm(path);
	string line;
	root->data == "ROOT";
	root->isWord == false;
	while (getline(strm, line))
	{
		//dictionary.push_back(line);
		if (line.length() > 3)
		{
			int firstChar = (int)(line[0] - 'a');
			Node* subNode = new Node;
			if (root->subNodes[firstChar] == NULL)
			{
				subNode->data = line[0];
				subNode->isWord = false;
				subNode->overNode = root;
				root->subNodes[firstChar] = subNode;
			}//if no nodes create
			else
			{
				subNode = root->subNodes[firstChar];
			}//else nodes exist, merely select
			buildSubtree(subNode, line, 1);
		}
	}//while getline
	test++;
	/*
	for (int alphIterator = 0; alphIterator < 26; alphIterator++)
	{
		Node* subNode = new Node;
		subNode->overNode = root;
		subNode->status = "PARTIAL";
		subNode->data = (char)(alphIterator + 97);
		root->subNodes[alphIterator] = subNode;
	}
	for (int nodeIterator = 0; nodeIterator < 26; nodeIterator++)
	{
		buildSubtree(root->subNodes[nodeIterator], 0);
	}
	test++;
	*/
}//buildTrie

//===========================================================================================
void Trie::buildSubtree(Node* newRoot, string word, int levelCount)
{
	//cout << newRoot->data  << " CallCount"<< test <<" Level"<< levelCount << endl;
	if (levelCount == 30)
		return;
	if (word.length() == levelCount)
	{
		newRoot->isWord = true;
		return;
	}//if word length
	int nextChar = (int)(word[levelCount] - 'a');
	levelCount++;
	Node* newNode = new Node;
	if (newRoot->subNodes[nextChar] == NULL)
	{
		newNode->isWord = false;
		newNode->data = word.substr(0, levelCount);
		newNode->overNode = newRoot;
		newRoot->subNodes[nextChar] = newNode;
		test++;
		buildSubtree(newNode, word, levelCount);
	}//if no newRoot
	else
	{
		/*newNode->data = word.substr(0, levelCount);
		newNode->overNode = newRoot;
		newRoot->subNodes[nextChar] = newNode;*/
		buildSubtree(newRoot->subNodes[nextChar], word, levelCount);
	}//else newRoot
}//buildSubTrie
void Trie::dictTest()
{
	int blah = 0;
	fstream strm(path);
	string line;
	while (getline(strm, line))
	{
		if (search(line) != "WORD")
		{
			cout << line << endl;
			blah++;
		}
	}
	cout << blah;
}
string Trie::search(string query)
{
	Node* firstChar = root->subNodes[int(query[0]) - 'a'];
	return searchNodes(firstChar, query, 1);
}
string Trie::searchNodes(Node* newRoot, string query, int levelCount)
{
	if (levelCount > query.length())
	{
		return "DEAD";
	}
	if (levelCount == query.length() && newRoot->data == query)
	{
		if (newRoot->isWord == true)
			return "WORD";
		else
			return "PARTIAL";
	}
	int queryLevelChar = int(query[levelCount]) - 'a';
	if (newRoot->subNodes[queryLevelChar] != NULL)
	{
		Node* nextChar = newRoot->subNodes[int(query[levelCount]) - 'a'];
		levelCount++;
		return searchNodes(nextChar, query, levelCount);
	}
	else
	{
		return "DEAD";
	}
}
Trie::~Trie()
{
	delete root;
}