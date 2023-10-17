#pragma once
#include <string>
#include "SafeArrayException.h"
using namespace std;

template < typename T >
class SafeArray
{
public:

    SafeArray();
    SafeArray(const SafeArray& original);
    ~SafeArray();
    int index; //nit: typically all members of the class would be listed after functions, also typically those are private, and we use getters. It may not make sense here, but it helps to debug code in multithreded environment when you don't know who and when is reading data. Same with setters.
    T* allVals;
    int totalSize;
    void resize(int newSize);
    void erase(int pos);
    void push_back(T newVal);
    void pop_back();
    int size();
    T& at(int pos);
    T& operator[](int pos);
    
private:

    void doubleAr();
    void halveAr();

};
//--
template < typename T >SafeArray<T>::SafeArray()
{
    index = 0;
    allVals = new T[10]; // nit: why not assign totalSize first and then use it here instead of hardcode 10 that you have to change twice. It's clear to you that it's the same thing but not to every reader in the future after your code is butchered many times. Just good to build good habits when you can.
    totalSize = 10;
}
//--
template < typename T >SafeArray<T>::SafeArray(const SafeArray& original)
{
    index = original.index;
    totalSize = original.totalSize;
    allVals = new T[totalSize];

    for (int i = 0; i < index + 1; i++)
    {
        allVals[i] = original.allVals[i];
    }
}
//--
template < typename T >SafeArray<T>::~SafeArray()
{
    delete[] allVals;
    allVals = NULL;
}
//--
template < typename T >void SafeArray<T>::resize(int newSize)
{
    delete[] allVals;
    T* newAr = new T[newSize * 2];
    index = newSize;
    allVals = newAr;
}
//--
template < typename T >void SafeArray<T>::erase(int pos)
{
    T* newAr = new T[totalSize];
    for (int i = 0; i < (totalSize/2); i++){
        if (i != pos) newAr[i] = allVals[i];
    }
    delete[] allVals;
    allVals = newAr;
    pop_back();
}
//--
template < typename T >void SafeArray<T>::push_back(T newVal)
{
    if (index == totalSize - 1) doubleAr();
    allVals[index] = newVal;
    index++;
}
//--
template < typename T >void SafeArray<T>::pop_back()
{
    if(index == 0) { //nit: though it won't be a problem here - single threaded environment, but it's best to do <=. Just little things that will save you tons of time of hair pulling in the future. Imagine two threads calling pop_back at the same time, your index might actually become -1. but it's outside of the scope of this project.
        SafeArrayException ex("Nothing to pop back!");
        throw ex;
    }
    
    if (index == totalSize / 4) halveAr();
    index--;
}
//--
template < typename T >int SafeArray<T>::size()
{
     return index;
}
//--
template < typename T >T& SafeArray<T>::at(int pos)
{
    if (pos > index - 1 or pos < 0){
        SafeArrayException ex("Out of Bounds!");
        printf("%s\n", ex.getStr());
        throw ex;
    }
    return allVals[pos];
}
//--
template < typename T >T& SafeArray<T>::operator[](int pos)
{
    return at(pos);
}
//--
template < typename T >void SafeArray<T>::doubleAr()
{
    totalSize *= 2;
    T* newAr = new T[totalSize];
    for (int i = 0; i < (totalSize/2); i++)
    { //nit: it will cause less problems in the future. I know it seems like saving vertical space and no big deal, but code blocks do help and make you look more experience....it means you already felt the pain of dealing with situations like this.
        newAr[i] = allVals[i];
    }
    delete[] allVals;
    allVals = newAr; 
}
//--
template < typename T >void SafeArray<T>::halveAr()
{
    totalSize /= 2;
    T* newAr = new T[totalSize];
    for (int i = 0; i < index; i++) newAr[i] = allVals[i];
    delete[] allVals;
    allVals = newAr;
}
