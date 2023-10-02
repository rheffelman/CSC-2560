#pragma once
#include <iostream>
using namespace std;
template < typename T >
class DoublyLinkedList{
public:
    DoublyLinkedList(){
        p_head = 0;
        p_tail = 0;
        p_current = 0;
        numElements = 0;
    }
    //--
    ~DoublyLinkedList(){
        Node* p_temp;
        for (;!isEmpty();){
            p_temp = p_head;
            p_head = p_head->p_next;
            cout << "Deleting: " << p_temp->data << endl;
            delete p_temp;                                      
            numElements--;
        }
    }
    //--
    void insertAtStart(const T& elem){
        Node* p_temp = new Node;
        p_temp->data = elem;
        p_temp->p_prev = NULL;
        if (!numElements){
                p_temp->p_next = NULL;
                p_head = p_temp;
                p_tail = p_temp;
                p_current = p_head;
        }
        else{
                p_temp->p_next = p_head;
                p_head = p_temp;
        }
        numElements++;
    }
    //--
    void insertAtBack(const T& elem){
        Node* p_temp = new Node;
        p_temp->data = elem;
        p_temp->p_next = NULL;
        if (!numElements){
                p_temp->p_prev = NULL;
                p_head = p_temp;
                p_tail = p_temp;
                p_current = p_tail;
        }
        else{
                p_tail->p_next = p_temp;
                p_temp->p_prev = p_tail;
                p_tail = p_temp;
        }
        numElements++;
    }
    //--
    bool removeFromFront (T& elem){
        Node* p_temp;
        if (p_head == 0) return false;
        p_temp = p_head;
        p_head = p_temp->p_next;
        p_head->p_prev = NULL;
        elem = p_temp->data;
        delete p_temp;
        numElements--;
        return true;
    }
    //--
    bool removeFromRear (T& elem){
        Node* p_temp;
        if (p_tail == 0) return false;
        p_temp = p_tail;
        p_tail = p_temp->p_prev;
        p_tail->p_next = NULL;
        elem = p_temp->data;
        delete p_temp;
        numElements--;
        return true;
    }
    //--
    bool remove(){
        if (p_current == p_head){
            Node* a = p_head;
            p_head->p_next->p_prev = NULL;
            p_head = p_head->p_next;
            delete a;
        }
        else if (p_current == p_tail){
            Node* a = p_tail;
            p_tail->p_prev->p_next = NULL;
            p_tail = p_tail->p_prev;
            delete a;
        }
        else{
            p_current->p_next->p_prev = p_current->p_prev;
            p_current->p_prev->p_next = p_current->p_next;
            delete p_current;
            p_current = p_head;
        }
        numElements--;
        return true;
    }
    //--
    bool removeAll(const T& elem){
        Node* a = p_head;

        for (;a;){
            if (a->data == elem){
                p_current = a;
                remove();
                a = p_head;
                continue;
            }
            a = a->p_next;
        }
        return true;
    }
    //--
    bool first(T& elem){
        bool retVal = false;
        if (!isEmpty()){
            retVal = true;
            elem = p_head->data;
            p_current = p_head;
        }
        return retVal;
    }
    //--
    bool last(T& elem){
        bool retVal = false;
        if (!isEmpty()){
            retVal = true;
            elem = p_tail->data;
            p_current = p_tail;
        }
        return retVal;
    }
    //--
    bool next(T& elem){
        bool retVal = false;
        if (p_current->p_next != 0){
            p_current = p_current->p_next;
            retVal = true;
            elem = p_current->data;     
        }
        return retVal;
    }
    //--
    bool previous(T& elem){
        bool retVal = false;
        if (p_current->p_prev != 0){
            p_current = p_current->p_prev;
            retVal = true;
            elem = p_current->data;
        }
        return retVal;
    }
    //--
    int size(){
        return numElements;
    }
    //--
    bool isEmpty(){
        return(size() == 0);
    }
    //--
    bool find(const T& elem){
        Node* a = p_head;
        for (;a;){
            if (a->data == elem) return true;
            a = a->p_next;
        }
        return false;
    }
    //--
    T& at(int pos){
        Node* a = p_head;
        for (int i = 0; i < pos; i++){
            if (a){
                a = a->p_next;
            }
        }
        return a->data;
    }
    //--
    T& operator[](int pos){
        return at(pos);
    }
private:
    struct Node{
        T data;
        Node* p_prev;
        Node* p_next;
    };
    Node* p_head;
    Node* p_tail;
    Node* p_current;
    int numElements;
};