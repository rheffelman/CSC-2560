#pragma once
using namespace std;
#include <iostream>
#include <cassert>

template < typename T >
class SafeArray
{
public:
    /*SafeArray(const SafeArray& original)
    {
        arrSize = original.size();
        data = new data[arrSize];
        for (int i = 0; i < T.size(); i++)
        {
            data[i] = original[i];
        }
    }*/
    SafeArray()
    {
    }
    void erase(int pos)
    {
        int iArrSize = size();
        for (int i = pos; i < iArrSize - 1; i++)
        {
            data[i] = data[i + 1];
            
        }
        filledSize--;
        if (iArrSize * 4 < arrSize)
        {
            T* tempArr = new T[iArrSize];
            arrSize = iArrSize;
            for (int dataCleaner = 0; dataCleaner < iArrSize; dataCleaner++)
            {
                tempArr[dataCleaner] = data[dataCleaner];
            }
            delete[] data;
            data = tempArr;
        }
    }
    void pushBack(const T& elem)
    {
        int iArrSize = size();
        if (iArrSize < arrSize)
        {
            data[iArrSize] = elem;
            filledSize++;
        }
        else
        {
            T* tempArr = new T[iArrSize * 2];
            arrSize *= 2;
            for (int dataIterator = 0; dataIterator < iArrSize; dataIterator++)
            {
                tempArr[dataIterator] = data[dataIterator];
            }
            delete[] data;
            data = tempArr;
            data[iArrSize] = elem;
            filledSize++;
            iArrSize = 0;
        }
    }
    T popBack()
    {
        int iArrSize = filledSize;
        if (iArrSize * 4 >= arrSize)
        {
            T temp = data[iArrSize - 1];
            filledSize--;
            return temp;
        }
        else
        {
            T blah2 = data[iArrSize - 1];
            T* tempArr = new T[iArrSize];
            arrSize = iArrSize;
            for (int dataCleaner = 0; dataCleaner < iArrSize; dataCleaner++)
            {
                tempArr[dataCleaner] = data[dataCleaner];
            }
            delete[] data;
            iArrSize = size();
            data = tempArr;
            filledSize--;
            return blah2;
        }
    }
    int size()
    {
        return filledSize;
    }
    T& at(int pos)
    {
        int iArrSize = size();
        if (pos < size())
            return(data[pos]);
        else
        {
            cout << "That was outside the bounds of the array! You tried to access index " << pos << " when the maximum current size is " << size();
            exit(0);
        }
    }
    T& operator[](int pos)
    {
            return at(pos);
    }
private:
	int arrSize = 10;
    T* data = new T[10];
    int filledSize = 0;
};/*
int main()
{
    //create a safe array
    SafeArray<char> s1;
    //verify that the number of used elements is 0

    assert(s1.size() == 0);
    //add 3 items
    s1.pushBack(10);
    s1.pushBack(20);
    s1.pushBack(30);

    //number of used elements is 3
    assert(s1.size() == 3);

    //retrieve the values by position
    assert(s1.at(0) == 10);
    assert(s1.at(1) == 20);
    assert(s1.at(2) == 30);

    //verify the overloaded operator []    
    assert(s1[0] == 10);
    assert(s1[1] == 20);
    assert(s1[2] == 30);

    //update the first two with at()
    s1.at(0) = 50;
    s1.at(1) = 40;

    //verify
    assert(s1.size() == 3);
    assert(s1.at(0) == 50);
    assert(s1.at(1) == 40);
    assert(s1.at(2) == 30);
    int blah = s1.size();
    //adding 100 random numbers
    for (int i = 1; i < 101; i++)
    {
        s1.pushBack(i);
    }
    int blah2 = s1.size();
    assert(s1.size() == 103);
    assert(s1.at(0) == 50);
    assert(s1.at(1) == 40);
    assert(s1.at(2) == 30);
    for (int i = 0; i < 100; i++)
    {
        s1.popBack();
    }

    //verify
    int blah3 = s1.size();
    assert(s1.size() == 3);
    assert(s1.at(0) == 50);
    assert(s1.at(1) == 40);
    assert(s1.at(2) == 30);

    //going outside the bounds, the program should end
    s1.at(3) = 40;
    cout << "You should not see this on the screen!" << endl;

    return 0;
}*/