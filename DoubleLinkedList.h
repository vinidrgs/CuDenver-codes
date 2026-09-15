/****************************************************************************************************
 * The DoubleLinkedList.h file contains two separate classes (Node and DoubleLinkedList). 
 * The Node class holds the data needed to create a new node and its pointers. 
 * The DoubleLinkedList class has a constructor and the functions necessary to manage the nodes in a Double Linked List.
 * Author: Vini Dargas
 * Version: 07/04/2026
 *******************************************************************************/

class Node{
    private:
    int data;
    Node* next;
    Node* previous;

    public:
    Node();//Default Constructor
    Node(const int newData);//Parameterized Constructor
    Node(const int newData, Node* nextNodePtr, Node* prevNodePtr);//Parameterized Constructor poiters are set null by default

    //Setters
    void setItem(const int newData);
    void setNext(Node* nextNodePtr);
    void setPrev(Node* prevNodePtr);

   //Getters
    int getData() const;
    Node* getNext() const;
    Node* getPrevius() const;
};

class DoubleLinkedList{
    private:
    Node* head;

    public:
    DoubleLinkedList();//Constructor start a list object with head set to nullptr
    bool isEmpty();//verify if list is empty
    void addNode(int newData);//Add a new node to the list
    void printList();//Print all the items in the list
    void removeNode(int anEntry);//Remove a node determined by the entry data
    int getSize();//return the size of the list
    int findNode(int dataToFind);//return the postion of a node
    void clear();//delete all the nodes in the list\
    
};
