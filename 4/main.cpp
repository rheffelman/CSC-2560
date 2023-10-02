#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <string>
#include <iostream>
using namespace std;
void print(DoublyLinkedList <string>& a);

int main(){
    DoublyLinkedList < string > a;
    a.insertAtBack("Hello");
    a.insertAtBack("Why");
    a.insertAtBack("World");
    a.insertAtBack("World");
    a.insertAtBack("Hi");
    a.insertAtBack("Why");

    string elem = a.at(0);
    
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
}
//--
void print(DoublyLinkedList <string>& a){
    string str;
    if (a.first(str)){
        cout << str << endl;
        for (;a.next(str);){
            cout << str << endl;
        }
    }
}