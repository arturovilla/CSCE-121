//
//  RPN.cpp
//  lab 7 RPN calculator
//
//  Created by Arturo Villalobos on 10/7/19.
//  Copyright © 2019 Arturo Villalobos. All rights reserved.
//


#include <iostream>
#include <cmath>
#include <string>
#include "Stack.h"

using namespace std;
int main()
{
    Stack s;
   
    string math;
    double popv = 0;
    double popl =0;
    double conversion = 0;
    double element = 0;
    
    cin>>math;
    
    
   
    do
    {
        if(isdigit(math.at(0)))
        {
            conversion = stod(math);
            push(s,conversion);
            
        }
        else if(math[0] =='.')
        {
            conversion = stod(math);
            push(s,conversion);
        }
        else if(math[0] =='*')
        {
            popv = pop(s);
            popl = pop(s);
            element = popl*popv;
            push(s,element);
            
        }
        else if(math[0] == '/')
        {
            popv = pop(s);
            popl = pop(s);
            element = popl/popv;
            push(s,element);
        }
        else if(math[0] == '+')
        {
            popv = pop(s);
            popl = pop(s);
            element = popl+popv;
            push(s,element);
            
        }
        else if(math[0] == '-')
        {
            popv = pop(s);
            popl = pop(s);
            element = popl-popv;
            push(s,element);
        }
        else
        {
            cout<<"[ERROR] invalid operator: "<<math<<endl;
            return -1;
        }
        cin>>math;
    }
    while(math.at(0) != '=');
    
    cout<<s.A[0]<<endl;
    
    
    
    
    
    delete [] s.A;
    
    
    
    
    
   
}
