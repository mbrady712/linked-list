/*********************
Name: Michael Brady
Programmin Fundamentals III
Purpose: This program contians a doubly Linked List ADT.
**********************/
#ifndef LINKED_LIST
#define LINKED_LIST

#include "data.h"

class LinkedList {

public:
    LinkedList();
    bool addNode(int, string*); 
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false); 
    int getCount();
    bool clearList();
    bool exists(int);
    ~LinkedList();

private:
    Node *head; 
    bool addFirst(Node*, bool);
    bool addHead(Node*, bool);
};

#endif //LINKED_LIST
