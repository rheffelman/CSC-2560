#pragma once
#include "Dictionary.h"
#include "Stack.h"
#include <string>
#include <iostream>
using namespace std;

class WordFinder
{
public:
    WordFinder(const string& dictionaryPath);
    void makeWordsFromWord(const string& word);
    void mwfwHelper(const string& word, int length, Stack < string > s);
    void printWords(Stack < string > k);
    Stack < string > words;
    bool check = false;
private:
    Dictionary* d;
    int x;
    int y;
    int count = 0;
};