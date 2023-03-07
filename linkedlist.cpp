/*********************
Name: Michael Brady
Programmin Fundamentals III
Purpose: This program contians a doubly Linked List ADT.
**********************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    Node *head = NULL;
}

bool LinkedList::addNode(int id, string* data){

    //create node dynamically
    Node *node = new Node;
    node->data.id = id;
    node->data.data = *data;


    return true;
}

bool LinkedList::deleteNode(int id){
    return true;
}

bool LinkedList::getNode(int id, Data* data){
    return true;
}

void LinkedList::printList(bool){

}

int LinkedList::getCount(){
    return 1;
}

bool LinkedList::clearList(){
    return true;
}

bool LinkedList::exists(int id){
    return true;
}

LinkedList::~LinkedList(){

}
