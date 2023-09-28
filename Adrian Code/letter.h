#pragma once
class letter
{
public:
	letter(char newLetter, int newPos)
	{
		character = newLetter;
		position = newPos;
	}
	letter();
	char character;
	int position;
};

