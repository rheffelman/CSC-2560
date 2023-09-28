#pragma once
#include "SafeArray.h"
class IntersectionContainer
{
public:
	IntersectionContainer(SafeArray<string> overArr, string originalWord);
	void add();
	SafeArray<string> getCommonElements();
private:
	SafeArray<string> overArr;
	string origWord;
};

