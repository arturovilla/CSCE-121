//
//  Stack.cpp
//  lab 7 RPN calculator
//
//  Created by Arturo Villalobos on 10/7/19.
//  Copyright © 2019 Arturo Villalobos. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include <cmath>
#include <string>
using namespace std;



void push(Stack& s, double element)
{
    //i need to create a new  array with double the length of the array in statck s
    
    // i need to add exsisting info from old array to new array along witb the new value
    
    // i need to delete the pointer to the old data
    
    // i need to point to the new data
    
    if(s.capacity>s.length)
    {
        s.A[s.length] = element;
        s.length+=1;
        return;
    }
    ///////////////////////////////////////

    double* newarray = new double[(s.capacity*2)];
        
    for(int i =0; i<(s.capacity*2); i++)
    {
        newarray[i] = 0;
    }
        //copy the old values to new array
        
    newarray[s.length] = element;
        
    for(int i = 0; i<(s.length); i++)
    {
        newarray[i] = s.A[i];
    }
    
    s.capacity *=2;
    s.length++;
    delete [] s.A; //prevents memory leak
        
    s.A = newarray;//removesd newarray from the scope
    newarray = nullptr;//
    
    
  
}


///////////////////////////////////////////////////////////////////////////////////////////

double pop(Stack& s)
{
    //i need to create a new  array with -1 the length of the array in statck s
    
    
    
    // i need to delete the pointer to the old data
    
    // i need to point to the new data
    
    
    if(s.length==0)
    {
        return NAN;
    }
    
    ////////////////////////////////////
    
    
   // double* newarray = new double[s.capacity-1];
    double popvalue = s.A[s.length-1]; // this ins the value im going to return
    
    s.length--;
    return popvalue;
    //newarray = nullptr;
    
    
   // return popvalue;
    
    

    
    //return 0.0;
    
}

double peek(const Stack s)
{
    if(s.length==0)
    {
        return NAN;
    }
    
    double popvalue = s.A[s.length-1]; // this ins the value im going to return
    
    //s.length--;
    return popvalue;
    
}
