#include "Dictionary.h"
#include "WordFinder.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    WordFinder f("bigDictionary.txt");
    string a = "carton";

    f.makeWordsFromWord(a);
    cout << "exited";
}
/*
    always break into 2 parts
    take what's in the rest of the string and pass it into the same function
    first is always in the dictionary, and if rest is nothing that's when you do the printing
    first and rest variables.
    helper might contain an extra vector of strings
    cleanse function!







*/