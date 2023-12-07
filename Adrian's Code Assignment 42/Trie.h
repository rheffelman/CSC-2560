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

//===========================================================================================