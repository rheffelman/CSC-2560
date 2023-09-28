#pragma once
#include <string>
#include "SafeArrayException.h"
using namespace std;
template < typename T >

class SafeArray{
public:
int index = 0;
T* allVals = new T[10];
int totalSize = 10;
//--
~SafeArray(){
    delete[] allVals;
    allVals = NULL;
}
//--
void resize(int newSize){
    delete[] allVals;
    T* newAr = new T[newSize * 2];
    index = newSize;
    allVals = newAr;
}
//--
void erase(int pos){
    T* newAr = new T[totalSize];
    for (int i = 0; i < (totalSize/2); i++){
        if (i != pos) newAr[i] = allVals[i];
    }
    delete[] allVals;
    allVals = newAr;
    pop_back();
}
//--
void push_back(T newVal){
    if (index == totalSize - 1) doubleAr();
    allVals[index] = newVal;
    index++;
}
//--
void pop_back(){
    if(index == 0) {
    SafeArrayException ex("Nothing to pop back!");
    throw ex;
    }
    if (index == totalSize / 4) halveAr();
    index--;
}
//--
int size(){
     return index;
}
//--
T& at(int pos){
    if (pos > index - 1 or pos < 0){
        SafeArrayException ex("Out of Bounds!");
        printf("%s\n", ex.getStr());
        throw ex;
    }
    return allVals[pos];
}
//--
T& operator[](int pos){
    return at(pos);
}
//--
private:
void doubleAr(){
    totalSize *= 2;
    T* newAr = new T[totalSize];
    for (int i = 0; i < (totalSize/2); i++) newAr[i] = allVals[i];
    delete[] allVals;
    allVals = newAr; 
}
//--
void halveAr(){
    totalSize /= 2;
    T* newAr = new T[totalSize];
    for (int i = 0; i < index; i++) newAr[i] = allVals[i];
    delete[] allVals;
    allVals = newAr;
}
};