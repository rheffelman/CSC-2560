#pragma once
#include <string>
using namespace std;

class SafeArrayException
{
public:

    SafeArrayException(const string& str); //same const string& but whatever - your code your rules
    string getStr();
    void setStr(string str);

private:

string errorMessage = "Exception";

};
