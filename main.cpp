#include <iostream>
#include "MyLinkedList.h"

using namespace std;

int main(){
    MyLinkedList list; // Initializes a list

    // Test if empty flag works
    if(list.isEmpty()){
        cout << "Empty List" << endl;
    } else {
        cout << "Not empty list" << endl;
    }

    // Adds 0 and 3 to the list
    list.insertFirst(0);
    list.insertFirst(3);

    //Adds five arbitrary elements to the list
    for(int i = 0; i < 5; i++){
        list.insertLast(i*3+2);
    }

    // Prints the list
    cout << list << endl;

    //So far Constructor, << overload and insert first/last work

    list.setAt(2000,2); // Replaces the value in 2 with a 2000
    cout << list << endl;

    cout << list.getAt(1) << endl;

    /* Border cases */
    list.setAt(-100,0); // Replaces the value of the first element with -100
    cout << list << endl;
    list.setAt(404,list.length()-1); // Replaces the value of the last element with a 404
    cout << list << endl;

    try{
        list.setAt(777,list.length()); //out of bounds action
        cout << list << endl;
    } catch(invalid_argument& e){
        cout << e.what() << endl; //prints exception
    }

    // Inserts a new value in pos 1
    list.insertAt(22340,1);
    cout << list << endl;

    /* Border cases */
    list.insertAt(22340,0); // insertion on First
    cout << list << endl;
    list.insertAt(22340,list.length()); // insertion on Last
    cout << list << endl;
    try{
        list.insertAt(22340,list.length()+1); // Invalid insertion oob
        cout << list << endl;
    } catch (invalid_argument& e){
        cout << e.what() << endl;
    }

    list.removeFirst(); // Deletes first element
    cout << list << endl;

    list.removeLast(); // Deletes last element
    cout << list << endl;

    list.removeAt(2); //Deletes third element
    cout << list << endl;

    /* Border cases */
    list.removeAt(0);// beginning
    cout << list << endl;
    list.removeAt(list.length()-1); // last element
    cout << list << endl;
    try{
        list.removeAt(list.length()); // Invalid deletion oob
        cout << list << endl;
    } catch (invalid_argument& e){
        cout << e.what() << endl;
    }

    // Test if empty flag works when list has elements
    if(list.isEmpty()){
        cout << "Empty List" << endl;
    } else {
        cout << "Not empty list" << endl;
    }

    // Tests first and last element query
    cout << "First: " << list.first() << "\nLast: " << list.last() << endl;

    return 0;
}

