#include "StackError.h"

StackError::StackError(string str)
{
    setStr(str);
}
//--
string StackError::getStr()
{
    return errorMessage;
}
//--
void StackError::setStr(string str)
{
    errorMessage = str;
}