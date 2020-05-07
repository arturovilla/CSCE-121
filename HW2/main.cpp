//
//  main.cpp
//  differentdigits
//
//  Created by Arturo Villalobos on 9/11/19.
//  Copyright © 2019 Arturo Villalobos. All rights reserved.
//

#include <iostream>
#include "functions.h"

using namespace std;




int main(int argc, const char * argv[]) {
    //int y =0;///for internal while loop
    int a;
    int b;
    int validnums=0;////these are my variables
    //////////////////////////////////////////////
   cout<<"Enter numbers a <= b: ";
    cin>>a>>b;
    ///////////////////////////////////////////////////////////
    if(a*b<=0 || a>=b  || a/b!=0 || b>=10000 || a>=10000)// this checks that a is less than b and both are positive integers and within range
    {
        cout<<"Invalid input"<<endl;
        return 0;
    }
    else//this is where the rest of the code is
    {
        
        for(int n=a;n<=b;n++)//im sorry i couldnt figure out how to do it with a nested for loop it would probs be faster that way
        {
            if(countDigitOccurrences(n,0)<=1 && countDigitOccurrences(n,1)<=1 && countDigitOccurrences(n,2)<=1 && countDigitOccurrences(n,3)<=1 && countDigitOccurrences(n,4)<=1 && countDigitOccurrences(n,5)<=1 && countDigitOccurrences(n,6)<=1 && countDigitOccurrences(n,7)<=1 && countDigitOccurrences(n,8)<=1 && countDigitOccurrences(n,9)<=1){
                validnums++;
            } 
        }
        
    }
    cout<<"There are "<<validnums<<" valid numbers between "<<a<<" and "<<b<<endl;
    return 0;
    
    
    
    
}
