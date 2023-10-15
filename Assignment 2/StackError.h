//if someone attempts to pop or top an empty stack
#pragma once
#include <string>
using namespace std;

class StackError
{

public:

    StackError(string str);
    string getStr();
    void setStr(string str);

private:

    string errorMessage = "Exception";

};