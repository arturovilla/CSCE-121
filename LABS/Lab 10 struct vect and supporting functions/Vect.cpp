#include "Vect.h"
#include <cstdlib>


Vect vect_construct(unsigned int n, int val)
{
    Vect newvect;
    newvect.capacity=(n*2);
    newvect.size = n;
    
    newvect.arr = new int[n*2];
    for(int i =0; i < n;i++)
    {
        newvect.arr[i] = val;
    }
    return newvect;
    
}
unsigned int vect_size(const Vect &v)
{
    return v.size;
}
unsigned int vect_capacity(const Vect &v)
{
    return v.capacity;
}
bool vect_empty(const Vect &v)
{
    if(v.size==0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//Resizes the v.arr so that its capacity is n.  If n is smaller than size, the Vect object is resized to hold only its first n elements; if n is larger than size, the v.arr is grown by “adding elements” at the end to reach capacity n.  Note: it is possible that both v’s capacity and size could change.
//
void vect_resize(Vect &v, unsigned int n)
{
    if(n<v.size)
    {
        int* newary = new int[n];
        for(int i =0;i<n;i++)
        {
            newary[i] = v.arr[i];
        }
        
        delete [] v.arr;
        v.arr=newary;
        v.size=n;
        v.capacity=n;
    }
    else if(n>v.size)//size stays the ssame
    {
        int *newary = new int[n];
        for(int i =0; i<v.size;i++)
        {
            newary[i]=v.arr[i];
        }
        delete [] v.arr;
        v.arr=newary;
        v.capacity= n;
        
    }
}

//Returns a reference to the element at position idx in v.arr (return v.arr[idx]).  This function checks whether idx is within the bounds of v’s valid elements [0...size-1] for arr.  If it is not, the program should terminate immediately (use exit(1)).
//What happens if you write int &r = vect_at(...); ++r; where … are valid arguments to the function.  Hint: look at the Vect argument’s arr thereafter.
//


int& vect_at(Vect &v, unsigned int idx)
{
    if(idx>v.size-1 || idx<0)
    {
        exit(1);
        
    }
    else
    {
        return v.arr[idx];
    }
    
}


//Removes from v.arr the element at idx.  This requires all elements in v.arr to be shifted down one position to fill idx and thus reduces v’s size by one. This function checks whether idx is within the bounds of v’s valid elements for arr.  If it is not, the program should terminate immediately (use exit(1)).
//


void vect_erase(Vect &v, unsigned int idx)
{
    if(idx>v.capacity || idx<0)
    {
        exit(1);
        
    }
    else
    {
        int* newa = new int[v.capacity];
        for(int i = 0; i<idx; i++)
        {
            newa[i]=v.arr[i];
        }
        for(int i =idx; i<v.size; i++)
        {
            newa[i] = v.arr[i+1];
        }
        delete [] v.arr;
        v.arr = newa;
        
        v.size-=1;
    }
}

//Adds val after the current last element in v’s arr.  This increases v’s size by 1.  If adding val causes v’s size to surpass its capacity, v’s arr must be resized so that its capacity is doubled.
void vect_push_back(Vect &v, int val)
{
    
    
    if(v.size+1>v.capacity)
    {
        //v.capacity=v.capacity*2;
        int* newa = new int[v.capacity*2];
        for(int i =0; i<v.size; i++)
        {
            newa[i]=v.arr[i];
        }
        delete [] v.arr;
        v.arr=newa;
        
        v.capacity=v.capacity*2;
    }
    
    
    
    v.arr[v.size] = val;
    v.size++;
   
    
     //v.capacity=v.capacity*2;
    
    
}

//Inserts the value val into position idx of v.   First, this function checks whether idx is within the bounds of v’s valid elements [0...size-1] for arr.  If it is not, the program should terminate immediately (use exit(1)).   The vect_insert() operation will shift all elements from idx up one position, thereby creating an opening at idx to place val. This increases v’s size by 1.   If v’s size surpasses its capacity, v’s array must be resized so that its capacity is doubled.


void vect_insert(Vect &v, unsigned int idx, int val)
{
  
    if(idx<0 || idx>v.size-1)
    {
        exit(1);
    }
    int* newary = new int[v.size+1];
    
    for(int i = 0; i<v.size;i++)
    {
        
        if(i>=idx)
        {
            newary[idx] = val;
            newary[i+1] = v.arr[i];
        }
        else
        {
            newary[i] = v.arr[i];
        }
    }
    v.size++;
    delete[]v.arr;
    v.arr = newary;
    if(v.size>v.capacity)
    {
        v.capacity=v.capacity*2;
    }
    
    
    
}


//Removes all elements from v’s array by setting the size of v to 0.  If the size is less than 20, you should not change the capacity of v nor deallocate memory of arr.  If the size is greater than or equal to 20, deallocate memory for v’s arr, assign v’s arr a new array of capacity 20, and set capacity to 20.




void vect_clear(Vect &v)
{
    if(v.size<20)
    {
        
        for(int i =0; i<v.capacity; i++)
        {
            v.arr[i] = 0;
        }
        
        v.size=0;
    }
    else if(v.size>=20)
    {
        int* newary = new int[20];
        for(int i = 0; i<20; i++)
        {
            newary[i]=0;
        }
        delete [] v.arr;
        v.arr = newary;
        v.capacity=20;
        v.size=0;
        
    }
    
    
}


//Destructs v as follows: deallocate memory for v’s arr, assigns arr nullptr, and sets v’s size and capacity to 0.

void vect_destruct(Vect &v)
{
    int* nullpt = nullptr;
    delete [] v.arr;
    v.arr=nullpt;
    v.size= 0;
    v.capacity=0;
}

//unsigned int Vect::getSize() const {
//    return this->size;
//}
