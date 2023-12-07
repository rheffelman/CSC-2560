#pragma once
#include <string>
using namespace std;
class BoggleDice
{
public:
	string showSide();
	string rollDice(int randNum);
	string sides[6];
	bool hasBeenCounted = false;
	string currentSide;
	~BoggleDice();
private:
};
string BoggleDice::rollDice(int randNum)
{
	currentSide = sides[randNum];
	return currentSide;
}
string BoggleDice::showSide()
{
	return currentSide;
}
BoggleDice::~BoggleDice()
{
	//delete sides;
}