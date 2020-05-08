//
//  Stack.h
//  LW 10 Stack with class
//
//  Created by Arturo Villalobos on 11/4/19.
//  Copyright © 2019 Arturo Villalobos. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef Stack_h
#define Stack_h//template only



 template <typename T>
 class Stack {
 private:
     unsigned int _size;
     unsigned int capacity;
     T* ary ;
 
 public:
     bool isEmpty() {if(_size==0){return true;}else{return false;}}
     unsigned int size() {return _size;}
     Stack() : _size(0), capacity(1) { ary = new T[1];}//defult constructor
     ~Stack(){_size =0;capacity=0;delete [] ary;ary=nullptr;}// destructor
     Stack(int size, T val) : _size(size), capacity(2*size), ary(nullptr)
     {
         // create array;
         if (_size == 0) {
             capacity = 1;
         }
         ary = new T[capacity];
         for (unsigned int i=0; i<_size; ++i) {
             ary[i] = val;
         }
     }
     Stack(int capacity) : _size(0), capacity(capacity){ary = new T[capacity];}
     /////////////////////////////////////////////////////////////////////
     T pop()
     {
         if(_size==0)
         {
             exit(0);
         }
         
       
         T popvalue = ary[_size-1]; // this ins the value im going to return
         
         _size--;
         return popvalue;
     }
     /////////////////////////////////////////////////////////////////////
     void push(/*StackDouble& s*/ T element)
     {
         if(capacity>_size)
         {
             ary[_size] = element;
             _size+=1;
             return;
         }
         ///////////////////////////////////////
         
         T* newarray = new T[(capacity*2)];
         
         
         //copy the old values to new array
         
         newarray[_size] = element;
         
         for(int i = 0; i<(_size); i++)
         {
             newarray[i] = ary[i];
         }
         
         capacity *=2;
         _size++;
         delete [] ary; //prevents memory leak
         
         ary = newarray;//removesd newarray from the scope
         newarray = nullptr;//
//         if(capacity>_size)
//         {
//             ary[_size] = element;
//             _size+=1;
//             cout << " sixze and line 58 " <<_size<<endl;
//             return;
//         }
//         ///////////////////////////////////////
//
//         T* newarray = new T[(capacity*2)];
//
//         //copy the old values to new array
//
//         newarray[_size] = element;
//
//         for(int i = 0; i<(_size); i++)
//         {
//             newarray[i] = ary[i];
//         }
//
//         capacity *=2;
//         _size++;
//         cout << " sixze and line 76 " <<_size<<endl;
//         delete [] ary; //prevents memory leak
//
//         ary = newarray;//removesd newarray from the scope
//         newarray = nullptr;//
     }
     /////////////////////////////////////////////////////////////////
     T peek()
     {
        if(_size==0)
        {
            exit(0);
        }
             
        T popvalue = ary[_size-1]; // this ins the value im going to return
             
             //s.length--;
        return popvalue;
     }
 };


#endif /* Stack_h */
