#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#include <iostream>

using namespace std;

struct MyNodeLL{
    int data;
    MyNodeLL* next;

    MyNodeLL(int data, MyNodeLL* next){
        this->data = data;
        this->next = next;
    }

    explicit MyNodeLL(int data):MyNodeLL(data,nullptr){}
};


class MyLinkedList{
private:
    MyNodeLL* head;
    MyNodeLL* tail;
    int size;
public:
    MyLinkedList();
    ~MyLinkedList();
    int length() const;
    bool isEmpty() const;
    int first();
    int last();
    int getAt(int pos);
    void setAt(int data, int pos);
    void insertFirst(int data);
    void insertLast(int data);
    void insertAt(int data, int pos);
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    friend ostream& operator<<(ostream& os, const MyLinkedList& ll);
};
#endif // MY_LINKED_LIST_H