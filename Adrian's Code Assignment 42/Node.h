#pragma once
#include <string>
using namespace std;
class Node
{
public:
	bool isWord;
	string data;
	Node* overNode;
	Node* subNodes[26];
	~Node()
	{
		for (int i = 0; i < 26; i++)
		{
			delete subNodes[i];
		}
	}
};//class


