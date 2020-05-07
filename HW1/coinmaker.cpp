//
//  main.cpp
//  HW1 change maker
//
//  Created by Arturo Villalobos on 9/3/19.
//  Copyright © 2019 Arturo Villalobos. All rights reserved.
//
#include <iostream>
using namespace std;


int main()
{
    int quaters=0;
    int dimes=0;
    int nickles=0;
    int pennies=0;
    int wholed;
    int cents;
    int totalcoins=0;
    
    
    cout<<"Enter dollars: ";
    cin>>wholed;
    cout<<"Enter cents: ";
    cin>>cents;
    totalcoins+=(wholed*4);/// this accounting for the quaters used for the dollars
    //quaters+=(wholed*4);
    /////////
    quaters+=(cents/25); //find quaters
    cents=(cents-(25*quaters));// updates cent amount
    dimes+=(cents/10);
    cents=(cents-(10*dimes));
    nickles+=(cents/5);
    cents=(cents-(nickles*5));
    pennies+=cents;//this expression if diffrent becuase the left over coins would just be the individual pennies
    totalcoins+=quaters+dimes+nickles+pennies;//this updates the total coins
    
    quaters+=(wholed*4);
    cout<<"Pennies: "<<pennies<<endl;
    cout<<"Nickels: "<<nickles<<endl;
    cout<<"Dimes: "<<dimes<<endl;
    cout<<"Quarters: "<<quaters<<endl;
    cout<<endl;
    cout<<"Total coins used: "<<totalcoins<<endl;
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
