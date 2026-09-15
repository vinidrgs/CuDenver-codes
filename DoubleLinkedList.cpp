/********************************************
 * DoubleLinkedList.cpp file. It contains the function definitions for DoubleLinkedList.h. 
 * The constructors allow creating a node with only Data or with Data and pointers. 
 * The defined functions allow manipulating the nodes in a list, printing the information, 
 * finding node positions, and erasing all the nodes.
 * Author: Vini D.
 * Version: 07/04/2026
 *********************************************/

#include "DoubleLinkedList.h"
#include <iostream>
//Add and remove a node at the begin, middle or at the end of the list, following a growing sequence

Node::Node(){//Node constructor
    next = nullptr;
    previous = nullptr;
}
Node::Node(const int newData){//Node constructors parameterized
    data = newData;
    next = nullptr;
    previous = nullptr;
}

Node::Node(const int newData, Node* nextNodePtr, Node* prevNodePtr){
    data = newData;
    next = nextNodePtr;
    previous = prevNodePtr;
}
//Setters
void Node::setItem(const int newData){
    data = newData;
}

void Node::setNext(Node* nextNodePtr){
    next = nextNodePtr;
}

void Node::setPrev(Node* prevNodePtr){
    previous = prevNodePtr;
}

//Getters
int Node::getData() const{
    return data;
}

Node* Node::getNext() const{
    return next;
}

Node* Node::getPrevius() const{
    return previous;
}

//List constructor
DoubleLinkedList::DoubleLinkedList(){
   head = nullptr;
} 

//return if list is empty
bool DoubleLinkedList::isEmpty(){
    if(head == nullptr){
        return true;
    }return false;

}

void DoubleLinkedList::addNode(int newData){// Add a new node in four conditions
    Node* newNode = new Node(newData);

    if(isEmpty()){ //If the list is empty
    head = newNode;
    newNode->setNext(nullptr);
    newNode->setPrev(nullptr);
    }
    else if(newData < head->getData()){//If the newData is smaller then the current first item
        Node* current = head;
        head = newNode;
        newNode->setNext(current);
        current->setPrev(newNode);
    }else{
        Node* current = head;
        while(current->getNext() != nullptr && current->getNext()->getData() < newData){
            current = current->getNext(); //This loop traverse the list comparing the new entry with a current node
        }                                  
        if(current->getNext() == nullptr){//This case holds the possibility where the largest Node ios the last(poiting to nullptr)
            current->setNext(newNode);
            newNode->setPrev(current); 
            newNode->setNext(nullptr);
        }else{ //if the current node is smaller then the newData then inserts between the current and afterCurrent
            Node* afterCurrent = current->getNext();
            afterCurrent->setPrev(newNode);
            newNode->setNext(afterCurrent);
            newNode->setPrev(current);
            current->setNext(newNode);
        }
    }
}

void DoubleLinkedList::printList(){// traverse and print the data
    if(isEmpty()){return;}
    else{
        Node* current = head;
        while(current != nullptr){
            std::cout << current->getData() << " ";
            current = current->getNext();
        }
    }
}

//Similar to the addNode function, but instead it makes the connections if it is the first, last, or between two nodes.
void DoubleLinkedList::removeNode(int anEntry){
    if(isEmpty()){return;}
    else{
        Node* current = head;
        
        while(current != nullptr && current->getData() != anEntry){
            current = current->getNext();
        }

        if (current == nullptr) {//Item no found
            return; 
        }

        if(current->getPrevius() == nullptr){
            Node* afterCurrent = current->getNext();
            head = afterCurrent;
            if (afterCurrent != nullptr) {
                afterCurrent->setPrev(nullptr);
            }
            delete current;
        }else if(current->getNext() == nullptr){
            Node* beforeCurrent = current->getPrevius();
            beforeCurrent->setNext(nullptr);
            delete current;
        }else{
            Node* afterCurrent = current->getNext();
            Node* beforeCurrent = current->getPrevius();
            beforeCurrent->setNext(afterCurrent);
            afterCurrent->setPrev(beforeCurrent);
            delete current;               
        }
    }
}

int DoubleLinkedList::getSize(){//return the number of items in the list
    int count = 0;
    if(isEmpty()){return count;}

    else{
        Node* current = head;
        while(current != nullptr){
            count++;
            current = current->getNext();
        }
    }
    return count;
}

int DoubleLinkedList::findNode(int dataToFind){ //return the position of the node in the list
    if(isEmpty()){return -1;}
    else{
        int count = 0;
        Node* current = head;
        while(current != nullptr && current->getData() != dataToFind){
            count++;
            current = current->getNext();
        }
        if(current != nullptr){
            return count;
        }
        return -1;

    }
}

void DoubleLinkedList::clear(){ //Traverse and delete all the nodes
    if(isEmpty()){return;}
    else{
        Node* current = head;
        while(current != nullptr){
            Node* nextNode = current->getNext();
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
}