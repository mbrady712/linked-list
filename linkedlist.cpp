/*********************
Name: Michael Brady
Programmin Fundamentals III
Purpose: This program contians a doubly Linked List ADT.
**********************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

bool LinkedList::addNode(int id, string* data){
    bool success = false;

    //create node dynamically.
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;

    if(head == NULL){//If list is empty
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        success = true;
    }else if(id > 1){//Check if id is greater than 1
        Node *current = head; 
        while(current){
            if(id < head->data.id && success == false && id != head->data.id){//add new head case
                head->prev = newNode;
                newNode->next = head;
                newNode->prev = NULL;
                head = newNode;
                success = true;
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
