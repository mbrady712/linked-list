/*********************
Name: Michael Brady
Programmin Fundamentals III
Purpose: This program contians a doubly Linked List ADT.
**********************/

#include "linkedlist.h"

//Public methods

LinkedList::LinkedList(){
    head = NULL;
}

bool LinkedList::addNode(int id, string* data){
    bool success = false;

    //Create private helper functions for addFirst, addHead, addMiddle, addTail

    //create node dynamically.
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;

    //Verify that id is int
    if(head == NULL && id > 1){//If list is empty
        success = addFirst(newNode, success);
    }else if(id > 1){//Check if id is greater than 1
        Node *current = head; 
        while(current){
            if(id < head->data.id && success == false && id != head->data.id){//add new head case
                success = addHead(newNode, success);
            }else if(id < current->data.id && success == false && id != current->data.id){//general case
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                success = true;
            }else if(current->next == NULL && success == false && id != current->data.id){//add new tail case
                newNode->next = NULL;  
                newNode->prev = current;
                current->next = newNode;
                success = true;
            }
            current = current->next;
        }
    }
    return success;
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
    return 0;
}

bool LinkedList::clearList(){
    return true;
}

bool LinkedList::exists(int id){
    return true;
}

LinkedList::~LinkedList(){

}

//Private methods

bool LinkedList::addFirst(Node* newNode, bool success){
    head = newNode;
    newNode->next = NULL;
    newNode->prev = NULL;
    success = true;
    return success;
}

bool LinkedList::addHead(Node* newNode, bool success){
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
    success = true;
    return success;
}

