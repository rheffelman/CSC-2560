#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "SafeArray.h"
#include "SafeArrayException.h"
#include "Cell.h"
using namespace std;

class Map
{
public:

    Map(const string& pathToFile);
    ~Map();
    void printCells();
    void printRoute();
    
    Cell* getNorth(Cell* p_cell);
    Cell* getEast(Cell* p_cell);
    Cell* getSouth(Cell* p_cell);
    Cell* getWest(Cell* p_cell);
    Cell* getNorthEast(Cell* p_cell);
    Cell* getSouthEast(Cell* p_cell);
    Cell* getSouthWest(Cell* p_cell);
    Cell* getNorthWest(Cell* p_cell);
    Cell* getStart();
    Cell* getCell(int index);
    bool isFree(const Cell* c); //when I don't see const, I read it as data will be modified, so typically we add const to indicate that it's input data, and it won't be modified.
    Cell* getIfFree(const Cell* c);

private:

    int size = 0;
    SafeArray < Cell* > allCells;

};
