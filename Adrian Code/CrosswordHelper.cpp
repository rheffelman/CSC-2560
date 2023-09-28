// CrosswordHelper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include <string>
#include "SafeArray.h"
#include "IntersectionContainer.h"
using namespace std;
int main()
{
    string originalWord;
    cout << "Enter the word to be checked! Dashes for unknown letters." << endl;
    cin >> originalWord;
    int wordLength = originalWord.length();
    string line;
    ifstream myFile;
    myFile.open("bigDictionary.txt");
    SafeArray<string> overArr;
    int foocount = 0;
    if (myFile.is_open())
    {
        int whileCounter = 0;
        while (getline(myFile, line))
        {
            if (line.length() == wordLength)
            {
                overArr.pushBack(line);
            }
        }
        myFile.close();
    }
    else
    {
        cout << "File open error!" << endl;
    }
    IntersectionContainer container(overArr,originalWord);
    SafeArray<string> finalAnswer = container.getCommonElements();
    int finalSize = finalAnswer.size();
    for (int arrayIterator = 0; arrayIterator < finalSize; arrayIterator++)
    {
        string answer = finalAnswer.popBack();
        cout << answer << endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
