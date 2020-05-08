//
//  StackDouble.h
//  LW 10 Stack with class
//
//  Created by Arturo Villalobos on 11/4/19.
//  Copyright © 2019 Arturo Villalobos. All rights reserved.
//

#ifndef StackDouble_h
#define StackDouble_h
#include <iostream>
#include <string>
/*
 In summary, the templated class Stack definition in your Stack.h file needs to implement the constructor​, ​destructor​, and the ​isEmpty,​ ​push​, and ​pop​ functions.
 */

//code goes here







class StackDouble
{
    double* A = new double[1];    // array for storage
    int capacity = 1;       // capacity of A
    int length = 0;         // number of elements in A
public:
    StackDouble() = default;

    
    ///MEMBER FUNCTIONS
    // add element to the top of Stack s
    // if Stack s is full, resize the underlying array
    void push(double element);
    
    // remove and return the element on top of Stack s
    // if Stack s is empty, return NAN
    double pop();
    
    int getSize();
    int getCapacity();
    double peek();

    
};// Stack;




#endif /* StackDouble_h */
