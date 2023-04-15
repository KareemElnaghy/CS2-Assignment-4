//
//  main.cpp
//  CS2 Assignment 4
//
//  Created by Kareem Elnaghy on 4/15/23.
//

#include "LinkedList.h"
#include <vector>
#include <iostream>
using namespace std;

//Function Prototypes
void insertAfter(int, int, vector<int>&);
LinkedList createList(vector<int>&);
void printOccurrence(LinkedList);

int main()
{
    vector<int> values;
    int size,firstValue, secondValue;
    size=firstValue=secondValue=0;
    
    cout << "Enter the size of the vector: ";   //input the size of the vector
    cin >> size;
    
    if(size == 0)           //in the case the size inputed was zero, exits program
    {
        cout<<"No vector created!"<<endl;
        return 0;
    }
    
    cout << "Enter the values you would like to add to the vector: "<<endl; //input the values from the user
    for (int i = 0; i < size; i++)
    {
        int x = 0;
        cout<<"Value "<<i+1<<": ";
        cin >> x;
        
        values.push_back(x);//adds values taken from user to the vector
    }
    
    cout << "Insert the first and second value!" << endl;
    cin >> firstValue >> secondValue;
    
    insertAfter(firstValue, secondValue, values);   //calls the insertAfter function
    
    LinkedList numbers = createList(values);        //creates a new linked list and calls the createList function
    
    cout << "The Current Linked List: ";
    numbers.printList();                   //prints the linked list after final changes after occurences considered
    
    printOccurrence(numbers);                       //Calls function that prints the number of occurences for each value
    
    cout<<"The sum of the values in the linked list is "<<numbers.sumList()<<endl;  //outputs the sum of all the values in the nodes in the linked list
}

//Function Definitions
void insertAfter(int firstValue, int secondValue, vector<int>& vec) //Insert after function uses iterator to iterate through vector and adds the secondValue after every occurence of the first value in the vector
{
    if(vec.size()==1)  //checks if the vector consists of one element only
    {
        if(vec[0] == firstValue)
        vec.push_back(secondValue);
    }
    else
    {
        for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)  //loops to find each occurence and inserts secondValue after it
        {
            if (*(it) == firstValue)
            {
                it = vec.insert(it + 1, secondValue);
            }
        }
    }
}

LinkedList createList(vector<int>& vec)
{
    LinkedList list;        //create a object of Linked List

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) //Create nodes for each element in the vector
    {
        list.addNode(*(it));
    }
    
    Node* p = list.get_head();

    while (p != NULL)   //Outer loop will loop the elements one by one to compare with rest of the list (moves the p node)
    {
        Node* q = p->next;

        while (q != NULL)   //Inner loop iterates the rest of the list (moves the q node)
        {
            if (p->value == q->value)   //checks if there as been an occurence and if so removes the duplicate nodes add icnrements the counter for the respective node
            {
                Node* temp = q;
                q = q->next;
                list.removeNode(temp);
                p->counter++;
            }
            else        //q moves to next node otherwise
            {
                q = q->next;
            }
        }

        p = p->next;        //move p to the next node
    }
    return list;            //returns the newly formed list
}

void printOccurrence(LinkedList list)
{
    Node* q = list.get_head(); //mirror pointer
    cout<<"Number of Occurences:    ";  //traverses through linked list and displays the number of occurences under the printed linked list
    while (q != NULL)
    {
        cout << q->counter << " ";
        q = q->next;
    }
    cout<<endl;
}
