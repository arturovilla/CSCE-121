//
//  StackDouble.cpp
//  LW 10 Stack with class
//
//  Created by Arturo Villalobos on 11/4/19.
//  Copyright © 2019 Arturo Villalobos. All rights reserved.
//

#include "StackDouble.h"
#include <iostream>
#include <iostream>
#include "Stack.h"
#include <cmath>
#include <string>
using namespace std;



void StackDouble::push(/*StackDouble& s*/ double element)
{
   
    
    if(capacity>length)
    {
        A[length] = element;
        length+=1;
        return;
    }
    ///////////////////////////////////////
    
    double* newarray = new double[(capacity*2)];
    
    for(int i =0; i<(capacity*2); i++)
    {
        newarray[i] = 0;
    }
    //copy the old values to new array
    
    newarray[length] = element;
    
    for(int i = 0; i<(length); i++)
    {
        newarray[i] = A[i];
    }
    
    capacity *=2;
    length++;
    delete [] A; //prevents memory leak
    
    A = newarray;//removesd newarray from the scope
    newarray = nullptr;//
    
    
    
}


///////////////////////////////////////////////////////////////////////////////////////////

double StackDouble::pop()
{
    //i need to create a new  array with -1 the length of the array in statck s
    
    
    
    // i need to delete the pointer to the old data
    
    // i need to point to the new data
    
    
    if(length==0)
    {
        return NAN;
    }
    
    ////////////////////////////////////
    
    
    // double* newarray = new double[s.capacity-1];
    double popvalue = A[length-1]; // this ins the value im going to return
    
    length--;
    return popvalue;
    //newarray = nullptr;
    
    
    // return popvalue;
    
    
    
    
    //return 0.0;
    
}

double StackDouble::peek()
{
    if(length==0)
    {
        return NAN;
    }
    
    double popvalue = A[length-1]; // this ins the value im going to return
    
    //s.length--;
    return popvalue;
    
}
