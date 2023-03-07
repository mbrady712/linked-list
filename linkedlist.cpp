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

    //Check if id is positive int greater than 0 and that string is not empty
    if(id > 0 && *data != ""){
        if(head == NULL){//If list is empty
            success = addFirst(id, data, success);
        }else{
            Node *current = head; 
            while(success == false && id != current->data.id){
                if(id < head->data.id){//add new head case
                    success = addHead(id, data, success);
                }else if(id < current->data.id){//general case
                    success = addMiddle(id, data, current, success);
                }else if(current->next == NULL){//add new tail case
                    success = addTail(id, data, current, success);
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

bool LinkedList::addFirst(int id, string* data, bool success){
    //Create node dynamically
    Node *newNode = createNode(id, data);

    //Add it to the list
    head = newNode;
    newNode->next = NULL;
    newNode->prev = NULL;
    success = true;
    return success;
}

bool LinkedList::addHead(int id, string* data, bool success){
    Node *newNode = createNode(id, data);
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
    success = true;
    return success;
}

bool LinkedList::addMiddle(int id, string* data, Node* current, bool success){
    Node *newNode = createNode(id, data);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    success = true;
    return success;
}

bool LinkedList::addTail(int id, string* data, Node* current, bool success){
    Node *newNode = createNode(id, data);
    newNode->next = NULL;  
    newNode->prev = current;
    current->next = newNode;
    success = true;
    return success;
}

Node* LinkedList::createNode(int id, string* data){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    return newNode;
}

