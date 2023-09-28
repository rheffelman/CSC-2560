#pragma once
using namespace std;
template < typename T >

class LinkedList{
public:
Node* p_head = new Node;
int numElements;
struct Node{
        T data;
        Node* p_next;
};
LinkedList(){
    p_head = 0;
    numElements = 0;
}
//--
void insert(const T& elem){
    Node* p_newNode = new Node;
    p_newNode->data = elem;
    p_newNode->p_next = p_head;
    p_head = p_newNode;
    numElements++;
}
//--
int size(){
    return numElements;
}
bool isEmpty();
bool first(T& elem);
bool next(T& elem);
private:
};
