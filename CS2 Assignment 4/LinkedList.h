//
//  LinkedList.h
//  CS2 Assignment 4
//
//  Created by Kareem Elnaghy on 4/15/23.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
using namespace std;

struct Node
{
    int value;  //stores info
    Node* next; //points to the next node
    Node* back; //points to the previous node
    int counter;//counts the number of occurences of "value" in the linked list

    Node()          //constructor
    {
        counter = 1;
        value = 0;
        next = NULL;
        back = NULL;
    }
    
    ~Node()         //destructor
    {
    }
};

#endif /* LinkedList_h */
