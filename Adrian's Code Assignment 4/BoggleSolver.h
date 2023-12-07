#pragma once
#include <string>
#include <vector>
#include "BoggleDice.h"
#include "Trie.h"
using namespace std;
class BoggleSolver
{
public:
	BoggleSolver();
	void buildBoard();
	void buildDice(string diceSides[6], int row, int col);
	void assignFaces();
	BoggleDice dataBoard[5][5];
	vector<vector<string>> board;
	void printBoard();
	void solveBoard();
	vector<vector<string>> results;
	vector<string> finalWords;
	void printResults();
	~BoggleSolver();
private:
	void findWords(int row, int col, string totalWord);
	Trie trie;
	void cleanResults();
};
BoggleSolver::BoggleSolver()
{
	buildBoard();
}
void BoggleSolver::buildBoard()
{
	trie.buildTrie();
	srand(2);
	for (int rowCount = 0; rowCount < 5; rowCount++)
	{
		for (int colCount = 0; colCount < 5; colCount++)
		{
			BoggleDice newDice;
			dataBoard[rowCount][colCount] = newDice;
		}
	}
	assignFaces();

	srand(time(0));
	for (int rowCount = 0; rowCount < 5; rowCount++)
	{
		for (int colCount = 0; colCount < 5; colCount++)
		{
			dataBoard[rowCount][colCount].rollDice(rand() % 6);
		}
	}
}
void BoggleSolver::solveBoard()
{
	for (int rowCount = 0; rowCount < 5; rowCount++)
	{
		for (int colCount = 0; colCount < 5; colCount++)
		{
			findWords(rowCount, colCount, dataBoard[rowCount][colCount].showSide());
			for (int rowCount2 = 0; rowCount2 < 5; rowCount2++)
			{
				for (int colCount2 = 0; colCount2 < 5; colCount2++)
				{
					dataBoard[rowCount2][colCount2].hasBeenCounted = false;
				}
			}
		}
	}
	cleanResults();
}
void BoggleSolver::cleanResults()
{
	results.resize(25);
	for (int iter1 = 0; iter1 < finalWords.size(); iter1++)
	{
		for (int iter2 = 0; iter2 < finalWords.size(); iter2++)
		{
			if (finalWords[iter1] == finalWords[iter2] && iter1 != iter2 && finalWords[iter1] != "0")
			{
				finalWords[iter2] = "0";
			}
		}
	}
	vector<string>::iterator i = finalWords.begin();
	int counter = 0;
	while (true)
	{
		if (counter == finalWords.size() - 1)
		{
			break;
		}
		counter++;
		if (finalWords[counter] == "0")
		{
			finalWords.erase(i + counter);
			counter--;
		}
	}
	for (int i = 0; i < finalWords.size(); i++)
	{
		results[finalWords[i].size()].push_back(finalWords[i]);
	}
	printResults();
}
void BoggleSolver::printResults()
{
	for (int resultsIter = 0; resultsIter < results.size(); resultsIter++)
	{
		if (results[resultsIter].size() != 0)
		{
			cout << "Words of " << resultsIter << " length" << endl;
			for (int iter2 = 0; iter2 < results[resultsIter].size(); iter2++)
			{

				cout << results[resultsIter][iter2] << " ";
			}
			cout << endl;
		}

	}
	for (int i = 0; i < finalWords.size(); i++)
	{
		//cout << finalWords[i] << endl;
	}
	cout << endl << finalWords.size() << endl;
}
void BoggleSolver::findWords(int row, int col, string totalWord)
{
	dataBoard[row][col].hasBeenCounted = true;
	if (row > 0 && col > 0 && row < 4 && col < 4)
	{
		if (dataBoard[row - 1][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col + 1, newWord);
			}
		}
		if (dataBoard[row + 1][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col - 1, newWord);
			}
		}
		if (dataBoard[row + 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col, newWord);
			}
		}
		if (dataBoard[row][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col + 1, newWord);
			}
		}
		if (dataBoard[row + 1][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col + 1, newWord);
			}
		}
		if (dataBoard[row - 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col, newWord);
			}
		}
		if (dataBoard[row - 1][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col - 1, newWord);
			}
		}
		if (dataBoard[row][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col - 1, newWord);
			}
		}
	}
	else if (row == 0 && col == 0)
	{
		if (dataBoard[row + 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col, newWord);
			}
		}
		if (dataBoard[row][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col + 1, newWord);
			}
		}
		if (dataBoard[row + 1][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col + 1, newWord);
			}
		}
	}
	else if (row == 0 && col != 4)
	{
		if (dataBoard[row + 1][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col - 1, newWord);
			}
		}
		if (dataBoard[row + 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col, newWord);
			}
		}
		if (dataBoard[row][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col + 1, newWord);
			}
		}
		if (dataBoard[row + 1][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col + 1, newWord);
			}
		}
		if (dataBoard[row][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col - 1, newWord);
			}
		}
	}
	else if (row != 4 && col == 0)
	{
		if (dataBoard[row + 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col, newWord);
			}
		}
		if (dataBoard[row - 1][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col + 1, newWord);
			}
		}
		if (dataBoard[row][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col + 1, newWord);
			}
		}
		if (dataBoard[row + 1][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col + 1, newWord);
			}
		}
		if (dataBoard[row - 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col, newWord);
			}
		}
	}
	else if (row == 4 && col == 4)
	{
		if (dataBoard[row - 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col, newWord);
			}
		}
		if (dataBoard[row - 1][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col - 1, newWord);
			}
		}
		if (dataBoard[row][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col - 1, newWord);
			}
		}
	}
	else if (row == 4 && col != 0)
	{
		if (dataBoard[row - 1][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col + 1, newWord);
			}
		}
		if (dataBoard[row][col + 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col + 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col + 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col + 1, newWord);
			}
		}
		if (dataBoard[row - 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col, newWord);
			}
		}
		if (dataBoard[row - 1][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col - 1, newWord);
			}
		}
		if (dataBoard[row][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col - 1, newWord);
			}
		}
	}
	else if (row != 0 && col == 4)
	{
		if (dataBoard[row + 1][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col - 1, newWord);
			}
		}
		if (dataBoard[row + 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row + 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row + 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row + 1, col, newWord);
			}
		}
		if (dataBoard[row - 1][col].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col, newWord);
			}
		}
		if (dataBoard[row - 1][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row - 1][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row - 1, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row - 1, col - 1, newWord);
			}
		}
		if (dataBoard[row][col - 1].hasBeenCounted == false)
		{
			string newWord = totalWord + dataBoard[row][col - 1].showSide();
			if (trie.search(newWord) == "PARTIAL")
			{
				findWords(row, col - 1, newWord);
			}
			else if (trie.search(newWord) == "WORD")
			{
				finalWords.push_back(newWord);
				findWords(row, col - 1, newWord);
			}
		}
	}
	else if (row == 4 && col == 0)
	{
	
	if (dataBoard[row - 1][col].hasBeenCounted == false)
	{
		string newWord = totalWord + dataBoard[row - 1][col].showSide();
		if (trie.search(newWord) == "PARTIAL")
		{
			findWords(row - 1, col, newWord);
		}
		else if (trie.search(newWord) == "WORD")
		{
			finalWords.push_back(newWord);
			findWords(row - 1, col, newWord);
		}
	}
	if (dataBoard[row - 1][col + 1].hasBeenCounted == false)
	{
		string newWord = totalWord + dataBoard[row - 1][col + 1].showSide();
		if (trie.search(newWord) == "PARTIAL")
		{
			findWords(row - 1, col + 1, newWord);
		}
		else if (trie.search(newWord) == "WORD")
		{
			finalWords.push_back(newWord);
			findWords(row - 1, col + 1, newWord);
		}
	}
	if (dataBoard[row][col + 1].hasBeenCounted == false)
	{
		string newWord = totalWord + dataBoard[row][col + 1].showSide();
		if (trie.search(newWord) == "PARTIAL")
		{
			findWords(row, col + 1, newWord);
		}
		else if (trie.search(newWord) == "WORD")
		{
			finalWords.push_back(newWord);
			findWords(row, col + 1, newWord);
		}
	}

	}
	else if (row == 0 && col == 4)
	{
	if (dataBoard[row][col - 1].hasBeenCounted == false)
	{
		string newWord = totalWord + dataBoard[row][col - 1].showSide();
		if (trie.search(newWord) == "PARTIAL")
		{
			findWords(row, col - 1, newWord);
		}
		else if (trie.search(newWord) == "WORD")
		{
			finalWords.push_back(newWord);
			findWords(row, col - 1, newWord);
		}
	}
	if (dataBoard[row + 1][col - 1].hasBeenCounted == false)
	{
		string newWord = totalWord + dataBoard[row + 1][col - 1].showSide();
		if (trie.search(newWord) == "PARTIAL")
		{
			findWords(row + 1, col - 1, newWord);
		}
		else if (trie.search(newWord) == "WORD")
		{
			finalWords.push_back(newWord);
			findWords(row + 1, col - 1, newWord);
		}
	}
	if (dataBoard[row + 1][col].hasBeenCounted == false)
	{
		string newWord = totalWord + dataBoard[row + 1][col].showSide();
		if (trie.search(newWord) == "PARTIAL")
		{
			findWords(row + 1, col, newWord);
		}
		else if (trie.search(newWord) == "WORD")
		{
			finalWords.push_back(newWord);
			findWords(row + 1, col, newWord);
		}
	}
	}
	dataBoard[row][col].hasBeenCounted = false;
}
void BoggleSolver::printBoard()
{
	for (int rowCount = 0; rowCount < 5; rowCount++)
	{
		for (int colCount = 0; colCount < 5; colCount++)
		{
			cout << dataBoard[rowCount][colCount].showSide() << " ";
		}
		cout << endl;
	}
}
void BoggleSolver::assignFaces()
{
	int arrSize = 24;
	string flatArr[25][7] =
	{
		{ "N", "S", "C", "T", "E", "C" },
		{ "A", "E", "A", "E", "E", "E" },//
		{ "H", "H", "L", "R", "O", "D" },//
		{ "O", "R", "W", "V", "G", "R" },//
		{ "S", "P", "R", "I", "Y", "Y" },//
		{ "S", "U", "E", "N", "S", "S" },//
		{ "M", "E", "A", "U", "E", "G" },
		{ "S", "E", "P", "T", "I", "C" },//
		{ "D", "H", "H", "O", "W", "N" },
		{ "L", "E", "P", "T", "I", "S" },//
		{ "S", "T", "L", "I", "E", "I" },//
		{ "A", "R", "S", "I", "Y", "F" },
		{ "T", "E", "T", "I", "I", "I" },
		{ "O", "T", "T", "T", "M", "E" },//
		{ "N", "M", "N", "E", "G", "A" },//
		{ "N", "N", "E", "N", "A", "D" },//
		{ "O", "U", "O", "T", "T", "O" },//
		{ "B", "Z", "J", "B", "X", "K" },//
		{ "A", "A", "F", "A", "S", "R" },
		{ "T", "O", "O", "U", "W", "N" },//
		{ "O", "T", "H", "D", "D", "N" },//
		{ "R", "A", "A", "S", "F", "I" },
		{ "H", "O", "D", "R", "L", "N" },
		{ "E", "E", "E", "E", "A", "M" },//
		{ "He", "Qu", "Th", "In", "Er", "An" }
	};
	for (int iter = 0; iter < 25; iter++)
	{
		for (int iter2 = 0; iter2 < 6; iter2++)
		{
			char c = flatArr[iter][iter2][0];
			c += 32;
			flatArr[iter][iter2][0] = c;
		}
	}
	int count = 0;
	for (int rowIter = 0; rowIter < 5; rowIter++)
	{
		
		srand(time(0));
		for (int colIter = 0; colIter < 5; colIter++)
		{
			bool flipDir = false;
			int loc = rand() % arrSize;
			int oriLoc = loc;
			while (flatArr[loc][6] == "~")
			{
				if (flipDir == false)
				{
					loc++;
					if (loc == 25)
					{
						flipDir = true;
						loc = oriLoc;
					}
				}
				else if (flipDir == true)
				{

					loc--;
					if (loc == -1)
					{
						flipDir = false;
						loc = oriLoc;
					}
				}
			}
			flatArr[loc][6] = "~";
			//cout << flatArr[count][0];
			buildDice(flatArr[loc], rowIter, colIter);

			count++;
		}
	}
	/*string tempArr1[6] = {"n", "s", "c", "t", "e", "c"};
	buildDice(tempArr1, 0, 0);
	string tempArr2[6] = { "a", "e", "a", "e", "e", "e" };
	buildDice(tempArr2, 0, 1);
	string tempArr3[6] = { "h", "h", "l", "r", "o", "d" };
	buildDice(tempArr3, 0, 2);
	string tempArr4[6] = { "o", "r", "w", "v", "g", "r" };
	buildDice(tempArr4, 0, 3);
	string tempArr5[6] = { "s", "p", "r", "i", "y", "y" };
	buildDice(tempArr5, 0, 4);
	string tempArr6[6] = { "s", "u", "e", "n", "s", "s" };
	buildDice(tempArr6, 1, 0);
	string tempArr7[6] = { "m", "e", "a", "u", "e", "g" };
	buildDice(tempArr7, 1, 1);
	string tempArr8[6] = { "s", "e", "p", "t", "i", "c" };
	buildDice(tempArr8, 1, 2);
	string tempArr9[6] = { "d", "h", "h", "o", "w", "n" };
	buildDice(tempArr9, 1, 3);
	string tempArr10[6] = { "l", "e", "p", "t", "i", "s" };
	buildDice(tempArr10, 1, 4);
	string tempArr11[6] = { "s", "t", "l", "i", "e", "i" };
	buildDice(tempArr11, 2, 0);
	string tempArr12[6] = { "a", "r", "s", "i", "y", "f" };
	buildDice(tempArr12, 2, 1);
	string tempArr13[6] = { "t", "e", "t", "i", "i", "i" };
	buildDice(tempArr13, 2, 2);
	string tempArr14[6] = { "o", "t", "t", "t", "m", "e" };
	buildDice(tempArr14, 2, 3);
	string tempArr15[6] = { "n", "m", "n", "e", "g", "a" };
	buildDice(tempArr15, 2, 4);
	string tempArr16[6] = { "n", "n", "e", "n", "a", "d" };
	buildDice(tempArr16, 3, 0);
	string tempArr17[6] = { "o", "u", "o", "t", "t", "o" };
	buildDice(tempArr17, 3, 1);
	string tempArr18[6] = { "b", "z", "j", "b", "x", "k" };
	buildDice(tempArr18, 3, 2);
	string tempArr19[6] = { "a", "a", "f", "a", "s", "r" };
	buildDice(tempArr19, 3, 3);
	string tempArr20[6] = { "t", "o", "o", "u", "w", "n" };
	buildDice(tempArr20, 3, 4);
	string tempArr21[6] = { "o", "t", "h", "d", "d", "n" };
	buildDice(tempArr21, 4, 0);
	string tempArr22[6] = { "r", "a", "a", "s", "f", "i" };
	buildDice(tempArr22, 4, 1);
	string tempArr23[6] = { "h", "o", "d", "r", "l", "n" };
	buildDice(tempArr23, 4, 2);
	string tempArr24[6] = { "e", "e", "e", "e", "a", "m" };
	buildDice(tempArr24, 4, 3);
	string tempArr25[6] = { "he", "qu", "th", "in", "er", "an" };
	buildDice(tempArr25, 4, 4);*/
}
void BoggleSolver::buildDice(string diceSides[6], int row, int col)
{
	for (int i = 0; i < 6; i++)
	{
		dataBoard[row][col].sides[i] = diceSides[i];
	}
}
BoggleSolver::~BoggleSolver()
{
	//delete dataBoard;
}