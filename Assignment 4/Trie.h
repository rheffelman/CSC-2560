#pragma once
#include "TrieElement.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef TrieElement Node;

class Trie
{
public:

    Trie(const string& filepath);
    ~Trie();
    TrieElement* p_root = new TrieElement(char(NULL));

private:

    string search(const string& word);
    string searchHelper(const string& word, Node* c, int index);
    void printAllWords();
    void printHelper(Node* c);
    void insert(const string& elem, TrieElement* c, int elemIndex);
    string cleanse(const string& word);
    
};