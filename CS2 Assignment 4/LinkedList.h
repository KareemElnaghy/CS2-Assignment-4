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

class LinkedList
{
private:
    Node* head;
    Node* tail;
    
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    //getters
    Node* get_head()
    {
        return head;
    }
       
    Node* get_tail()
    {
        return tail;
    }
        
        
    Node* addNode(int x)
        {
            Node* temp = new Node();    //creates a temporary node
            
            temp->value = x;         //sets the value of the node to be info
            
            if (head == NULL)           //incase it is the first node being added to the linked list
            {
                head = temp;
                tail = head;
            }
            
            else {
                temp->back=tail;        //otherwise it will set the back pointer to point on the last current last node (tail)
                tail->next =temp;       //the tail node next pointer will point to the new node
                temp->next= NULL;       //the new nodes next will point to NULL as it is the last in the list
                tail = tail->next;      //the tail pointer will now point to the new node as it is last in the list
            }
            return temp;
        }
    
    void removeNode(Node* remNode)
    {
        // In the case the node to remove is the first node
        if (head == remNode)
        {
            head = head->next;
            
            if (head != NULL)
            {
                head->back = NULL;
            }
            delete remNode;
        }

        Node* previous = head;    //lagging pointer that points to the node before the one to be deleted
        //traverse previous to the node before the node meant to be removed
        while (previous != NULL && previous->next != remNode)
        {
            previous = previous->next;
        }

        if (previous == NULL)   //Nodes do not exist
        {
            cout<<"Linked List is empty"<<endl;
            return;
        }

        // Update next pointer of previous node to point to the node next to the node to be removed
        previous->next = remNode->next;
        if (remNode->next != NULL)
        {
            remNode->next->back = previous; // Update back pointer of the next node to point to the previous node
        }
        
        delete remNode; //Deletes the node
    }

    void printList() const
     {
         Node* q; //mirror pointer
         q=head;
         
         while(q!= NULL) //traverses through the linked list outputing each value in the nodes
         {
             cout << q-> value<<" ";
             q=q->next;
         }
        cout<<endl;
     }
    
    int sumList()
    {
        int sum=0;
        Node* q = this->get_head(); //mirror pointer
        
        while(q!= NULL) // traverses through linked list adding each value stored in node
        {
            sum+= q->value;
            
            q=q->next;
        }
        
        return sum;
    }
    
    int sumListOccur()
    {
        int sum=0;
        Node* q = this->get_head(); //mirror pointer
        
        while(q!= NULL) // traverses through linked list adding each value stored in node
        {
            sum+= (q->value)*(q->counter);
            
            q=q->next;
        }
        
        return sum;
    }
};

#endif /* LinkedList_h */
