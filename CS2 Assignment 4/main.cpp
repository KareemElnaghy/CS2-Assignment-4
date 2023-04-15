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

void insertAfter(int, int, vector<int>&);

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
}

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
