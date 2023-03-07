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

    //create node dynamically.
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;

    //Verify that id is int and restructure logic to correctly ignore duplicate ids
    //Check if id is positive int greater than 0
    if(id > 0){
        if(head == NULL){//If list is empty
            success = addFirst(newNode, success);
        }else{
            Node *current = head; 
            while(success == false && id != current->data.id){
                if(id < head->data.id){//add new head case
                    success = addHead(newNode, success);
                }else if(id < current->data.id){//general case
                    success = addMiddle(newNode, current, success);
                }else if(current->next == NULL){//add new tail case
                    success = addTail(newNode, current, success);
                }
                current = current->next;
            }
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

bool LinkedList::addMiddle(Node* newNode, Node* current, bool success){
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    success = true;
    return success;
}

bool LinkedList::addTail(Node* newNode, Node* current, bool success){
    newNode->next = NULL;  
    newNode->prev = current;
    current->next = newNode;
    success = true;
    return success;
}

