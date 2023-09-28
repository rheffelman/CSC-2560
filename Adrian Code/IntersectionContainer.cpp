#include "IntersectionContainer.h"
#include <string>
#include "letter.h"
IntersectionContainer::IntersectionContainer(SafeArray<string> overArray, string originalWord)
{
	overArr = overArray;
	origWord = originalWord;
}
SafeArray<string> IntersectionContainer::getCommonElements()
{
	int overArrSize = overArr.size();
	int wordLength = origWord.length();
	int knownLetterCount = 0;
	SafeArray<int> origWordPos;
	//SafeArray<SafeArray<string>>;
	//Encode the origWord as an array of objects, each object has known letter and position.
	for (int wordIterator = 0; wordIterator < wordLength; wordIterator++)
	{
		if (origWord[wordIterator] != '-')
		{
			origWordPos.pushBack(wordIterator);
			knownLetterCount++;
		}//if not blank
	}//for wordIterator
	//construct an outer array of inner arrays of possible words from the dictionary.  
	//each inner array will have all the words in the dictionary that might match based on just one letter.
	//the outer array will have a number of inner arrays equal to the number of known letters in the original word.
	SafeArray<SafeArray<string>> outerArr;
	for (int innerArrayIndex = 0; innerArrayIndex < knownLetterCount; innerArrayIndex++)
	{
		SafeArray<string> innerArr;
		outerArr.pushBack(innerArr);
		for (int possibleMatchIndex = 0; possibleMatchIndex < overArrSize; possibleMatchIndex++)
		{
			if (overArr[possibleMatchIndex].at(origWordPos[innerArrayIndex]) == origWord[origWordPos[innerArrayIndex]])
			{
				outerArr[innerArrayIndex].pushBack(overArr[possibleMatchIndex]);
			}//if this word in the dictionary is qualified to be inserted into the inner array.
		}//for possible match in the entire dictionary
	}//for inner array index of known letters in original word

	//We are mostely done, we have an outer array of inner arrays.
	//Now all we need is to find the intersection of all of the inner arrays.
	SafeArray<string> finalArray = outerArr[0];
	for (int finalArrayIndex = 0; finalArrayIndex < finalArray.size(); finalArrayIndex++)
	{
		SafeArray<int> trueChecker;
		for (int outerArrIndex = 1; outerArrIndex < outerArr.size(); outerArrIndex++)
		{
			
			for (int innerArrIndex = 0; innerArrIndex < outerArr[outerArrIndex].size(); innerArrIndex++)
			{
				if (finalArray[finalArrayIndex] == outerArr[outerArrIndex][innerArrIndex])
				{
					trueChecker.pushBack(1);
				}
				//if(finalArray[finalArrayIndex])
			}
		}//for innerArrIndex
		if (trueChecker.size() != outerArr.size()-1)
		{
			int checkerSize = trueChecker.size();
			for (int checkerIterator = 0; checkerIterator < checkerSize; checkerIterator++)
			{
				trueChecker.erase(0);
			}
			string toBeErased = finalArray[finalArrayIndex];
			finalArray.erase(finalArrayIndex);
			finalArrayIndex--;
		}

	}
	return finalArray;
}//function getCommonElements