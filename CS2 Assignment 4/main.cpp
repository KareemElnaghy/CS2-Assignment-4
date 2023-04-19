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

