#include <iostream>
#include <string>
#include "MyLinkedList.h"

using namespace std;

//O(1)
MyLinkedList::MyLinkedList(){
    this->head = this->tail = nullptr; //Initialize on nullptr
    this->size = 0;
}

//O(n)
MyLinkedList::~MyLinkedList(){
    int totalSize = this->size;
    for(int i = 0; i < totalSize; i++){
        removeFirst(); //deletes every node from the beginning to the end of the list
    }
}

//O(1)
int MyLinkedList::length() const{
    return this->size;
}

//O(1)
bool MyLinkedList::isEmpty() const{
    return this->size == 0;
}

//O(1)
int MyLinkedList::first(){
    return this->head->data; //returns the value the head holds
}

//O(1)
int MyLinkedList::last(){
    return this->tail->data; //returns the value the tail holds
}

//O(n)
int MyLinkedList::getAt(int pos){
    if(pos>=0 && pos<this->size){ //Domain of the list
        MyNodeLL* current = this->head; // Initiate at the beginning of the list
        for(int i=0;i<pos;i++){ // Goes through the list until it reaches pos
            current = current->next; // Current advances to next
        }
        return current->data; // Returns data current holds
    } else { //Out of bounds
        throw invalid_argument("Couldn't return element in pos "+to_string(pos)+", list size is "+to_string(size)+".");
    }
}

//O(n)
void MyLinkedList::setAt(int data, int pos){
    if(pos>=0 && pos < this->size){ //limits
        MyNodeLL* current = this -> head; // Starts
        for(int i = 0; i < pos; i++){
            current = current-> next; //advances current to pos
        }
        current->data = data; // Replaces data on current with new data given
    } else { //out of bounds
        throw invalid_argument("Couldn't set element in pos "+to_string(pos)+", list size is "+to_string(size)+".");
    }
}

//O(1)
void MyLinkedList::insertFirst(int data){
    // Creates a new Node which holds new data and points to the start of the list
    // then saves this node to the head
    this->head = new MyNodeLL(data,this->head);
    if(this->tail == nullptr){ // If list was empty
        this->tail = this->head; // Point tail to head, because there's only one element
    }
    this->size++; // updates size
}

//O(1)
void MyLinkedList::insertLast(int data){
    if(this->size > 0){ // If not empty
        // The tail's next points to a new node which next points to null and holds new data
        this -> tail -> next = new MyNodeLL(data);
        this->tail= this->tail->next; // Moves the tail to the new node
        this->size++; // updates size
    } else { // If empty
        insertFirst(data);
    }
}

//O(n)
void MyLinkedList::insertAt(int data, int pos){
    if(pos > 0 && pos < this->size){ // Limits
        MyNodeLL* current = this->head; // Starts
        for(int i = 0; i < pos-1; i++){
            current = current->next; // Goes through list until an element before size
        }
        // creates a new node which next point to the current next and holds new data
        // then points the current next to this new node
        current->next = new MyNodeLL(data,current->next);
        this->size++; //updates
    } else if(pos == 0){ // if at the beginning
        insertFirst(data);
    }else if(pos == this->size){ //if at last
        insertLast(data);
    } else { // out of bounds
        throw invalid_argument("Couldn't insert element in pos "+to_string(pos)+", list size is "+to_string(size)+".");
    }
}

//O(1)
void MyLinkedList::removeFirst(){
    if(size>0){
        MyNodeLL* tmp = this->head; // points tmp to the beginning
        this->head = this->head->next; // beginning now points to its next
        this->size--; // decreases size
        if(size == 0){
            this->tail = nullptr; //if no more elements, point tail to null
        }
        delete tmp; // frees memory retained by tmp
    } else { // Invalid action for an empty list
        throw invalid_argument("Can't remove first element of an empty list.");
    }
}

//O(n)
void MyLinkedList::removeLast(){
    if(this->size <= 1){
        removeFirst(); // If 1 or 0, goes to the already validated case
    } else {
        MyNodeLL* current = this->head; // Starts
        for(int i = 0; i < this->size-2; i++){
            current = current->next; // Goes through the list until an element before the last one
        }
        this->tail = current; // Points tail to the current element
        delete current->next; // deletes the next element
        this->tail->next = nullptr; // points the current's next to null
        this->size--; //updates
    }
}

//O(n)
void MyLinkedList::removeAt(int pos){
    if(pos > 0 && pos < this->size-1){ // limits
        MyNodeLL* current = this->head; // starts
        for(int i = 0; i < pos-1; i++){
            current =  current->next; // goes through the list until one before pos
        }
        MyNodeLL* tmp = current->next; // points tmp to the next element
        current->next = current->next->next; // points current next to its following element
        this->size--; // updates size
        delete tmp; // deletes tmp
    } else if(pos == 0){ // If beginning
        removeFirst();
    } else if(pos == size-1){ // If last
        removeLast();
    }else{ // out of bounds
        throw invalid_argument("Can't remove element at pos "+to_string(pos)+", list size is "+to_string(this->size));
    }
}

//O(n)
ostream& operator<<(ostream& os, const MyLinkedList& ll){
    if(ll.size == 0){ // if list is empty it doesn't print anything
        return os;
    }

    MyNodeLL* current = ll.head; // starts
    bool isNull = false; // assume the next pointer is not null
    while(!isNull){ // while it's not null
        os << current->data << ", "; // stream data and a comma space
        if(current->next == nullptr){ // if the next node is null
            isNull = true; //flag it
        }
        current = current->next; // advance
    }
    return os; // return stream result
}
