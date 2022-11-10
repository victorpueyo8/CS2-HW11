#pragma once
#include<iostream>

using namespace std;

class LinkedList
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        int value;           // The value in this node
        struct ListNode* next;  // To point to the next node
    };

    ListNode* head;            // List head pointer

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;
    }
    // Copy Constructor
   /* LinkedList(const LinkedList &obj)
    {
        if (obj.head == NULL) {
            head = NULL;
        }
    }*/

    // Destructor
    ~LinkedList();

    // Linked list operations
    void appendNode(int);
    void insertNode(int);
    void deleteNode(int);
    void displayList() const;
    void reverse();
    void search(int);
};

void LinkedList::appendNode(int num)
{
    ListNode* newNode;  // To point to a new node
    ListNode* nodePtr;  // To move through the list

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // If there are no nodes in the list
    // make newNode the first node.
    if (!head)
        head = newNode;
    else  // Otherwise, insert newNode at end.
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Find the last node in the list.
        while (nodePtr->next)
            nodePtr = nodePtr->next;

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void LinkedList::displayList() const
{
    ListNode* nodePtr;  // To move through the list

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse
    // the list.
    while (nodePtr)
    {
        // Display the value in this node.
        cout << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}
void LinkedList::reverse()
{
    ListNode* nodePtr;
    ListNode* previousNode;
    ListNode* next;

    nodePtr = head;
    previousNode = nullptr;

    while (nodePtr != nullptr) 
    {
        next = nodePtr->next;
        nodePtr->next = previousNode;
        previousNode = nodePtr;
        nodePtr = next;
    }
    head = previousNode;
    
    displayList();
}

void LinkedList::search(int v)
{
    ListNode* nodePtr;
    nodePtr = head;
    int found = 0;
    int i = 0;

    if (nodePtr != NULL) {
        while (nodePtr != NULL) {
            i++;
            if (nodePtr->value == v) {
                found++;
                break;
            }
            nodePtr = nodePtr->next;
        }
        if (found == 1) {
            cout << v << " is found at position = " << i << ".\n";
        }
        else {
            cout <<"-1.\n";
        }
    }
    else {
        cout << "The list is empty.\n";
    }
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void LinkedList::insertNode(int num)
{
    ListNode* newNode;					// A new node
    ListNode* nodePtr;					// To traverse the list
    ListNode* previousNode = nullptr;	// The previous node

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;

    // If there are no nodes in the list
    // make newNode the first node
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else  // Otherwise, insert newNode
    {
        // Position nodePtr at the head of list.
        nodePtr = head;

        // Initialize previousNode to nullptr.
        previousNode = nullptr;

        // Skip all nodes whose value is less than num.
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else  // Otherwise insert after the previous node.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void LinkedList::deleteNode(int num)
{
    ListNode* nodePtr;       // To traverse the list
    ListNode* previousNode = nullptr;  // To point to the previous node

    // If the list is empty, do nothing.
    if (!head)
        return;

    // Determine if the first node is the one.
    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list
        nodePtr = head;

        // Skip all nodes whose value member is 
        // not equal to num.
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list, 
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

LinkedList::~LinkedList()
{
    ListNode* nodePtr;   // To traverse the list
    ListNode* nextNode;  // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

