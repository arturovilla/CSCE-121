#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//                         class template definition                        //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList {
public:
    /* uncomment the declarations as you implement them */
    //////////////////////////////////////////////////////////////////------ALL CONSTRUCTORS AREE IN THE CLASS DECLARATION FOR EASE OF FINDING THEM
    
    DoublyLinkedList()
    {
        this->sz = 0;
        this->head = nullptr;
        this->tail = nullptr;
    };
    
     DoublyLinkedList(T data) : head(nullptr), tail(nullptr), sz(0)
    {
        
        head=new Node<T>(data);
        tail=head;
        sz+=1;
    };
    
     DoublyLinkedList(const DoublyLinkedList<T>& src): head(nullptr), tail(nullptr), sz(0)
    {
        Node<T>* n = src.head;
            while(n!=nullptr)
            {
                push_back(n->data);
                n=n->next;
            }
        
    };
    
     ~DoublyLinkedList()
    {
        clear();
    };
    
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
   
    unsigned int size() const { return sz; }
    T& front();
    const T& front() const;
     T& back();
    const T& back() const;
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    void erase(unsigned int idx)
    {
        if(idx==0)
        {
            pop_front();
        }
        else if(idx==sz-1)
        {
            pop_back();
        }
        else
        {
            Node<T>*deletenode=head;
            for(unsigned int i=0;i<idx;i++)
            {
                deletenode=deletenode->next;
            }
            deletenode->next->prev=deletenode->prev;
            deletenode->prev->next=deletenode->next;
            delete deletenode;
            sz=sz-1;
        }
        
    };
     void insert(T data, unsigned int idx);
    void clear();
    std::string to_str() const;
    // breaks encapsulation... gives operator== access to private data... not great approach, but makes the homework easier for you since we haven't talked about iterators :).
    template<typename U> friend bool operator==(DoublyLinkedList<U> const&, DoublyLinkedList<U> const&);
private:
    // do not change ordering.
    Node<T> *head;
    Node<T> *tail;
    unsigned int sz;
};

//////////////////////////////////////////////////////////////////////////////
//                       helper function declarations                       //
//////////////////////////////////////////////////////////////////////////////
template<typename T> std::ostream& operator<<(std::ostream &, DoublyLinkedList<T> const&);

template<typename T> bool operator==(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

template<typename T> bool operator!=(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

//////////////////////////////////////////////////////////////////////////////
//                     member template function definitions                 //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
T& DoublyLinkedList<T>::front()
{
    Node<T> *rnode = head;
    return rnode->data;
}
template<typename T>
const T& DoublyLinkedList<T>::front() const
{
    const Node<T> *rnode = head;
    return rnode->data;
}
template<typename T>
T& DoublyLinkedList<T>::back()
{
    Node<T> *rnode = tail;
    return rnode->data;
}
template<typename T>
const T& DoublyLinkedList<T>::back() const
{
    const Node<T> *rnode = tail;
    return rnode->data;
}

template<typename T>
void DoublyLinkedList<T>::clear() 
{
	Node<T> *deletenode =nullptr;
	while(head!=nullptr)
	{
		deletenode=head;
		head=head->next;
		delete deletenode;
	}
	
	this->head=nullptr;
	this->tail=nullptr;
	sz=0;
}
template<typename T>
void DoublyLinkedList<T>::push_back(T data)
{
	Node<T>* nodes= new Node<T>(data);
	if(head==nullptr)
	{
		head=nodes;
		tail=nodes;
		sz+=1;
	}
	else
	{
		tail->next=nodes;
		nodes->prev=tail;
		tail=nodes;
		sz+=1;
	}
	//head=nodes;

	
	
}	
template<typename T>
void DoublyLinkedList<T>::push_front(T data)
{
	Node<T>* nodes= new Node<T>(data);
    if(head==nullptr)
    {
        head=nodes;
        tail=nodes;
        sz+=1;
    }
    else
    {
        nodes->next=head;
        head->prev=nodes;
        head=nodes;
        sz+=1;
    }
    
}

template<typename T>
void DoublyLinkedList<T>::insert(T data, unsigned int idx)
{
	if(idx>sz)
	{
		return;
	}
	if(idx==0)
	{
		push_front(data);
		
	}
	else if(idx==sz)
	{
		push_back(data);
	}
	else{
		sz+=1;
		Node<T>* curr=head;
		for(int i=0; i<idx-1;i++)
		{
			curr=curr->next;
		}
		Node<T>* newnode=new Node<T>(data);
		newnode->next=curr->next;
		curr->next->prev=newnode;
		curr->next=newnode;
		newnode->prev=curr;
		
	}
}
//template<typename T>
//void DoublyLinkedList<T>::erase(unsigned int idx)
//{
//    if(idx==0)
//    {
//        pop_front();
//    }
//    else if(idx==sz-1)
//    {
//        pop_back();
//    }
//    else
//    {
//        Node<T>*deletenode=head;
//        for(unsigned int i=0;i<idx;i++)
//        {
//            deletenode=deletenode->next;
//        }
//        deletenode->next->prev=deletenode->prev;
//        deletenode->prev->next=deletenode->next;
//        delete deletenode;
//        sz=sz-1;
//    }
//
//}



template<typename T>
void DoublyLinkedList<T>::pop_back()
{
	if(tail==nullptr)
	{
		return;
		
	}
	if(head==tail)
	{
		Node<T>*temp=tail;
		this->head=nullptr;
		this->tail=nullptr;
		delete temp;
		sz=sz-1;
	}
	else{
		Node<T>*temp=tail;
		this->tail=temp->prev;
		tail->next=nullptr;
		delete temp;
		sz=sz-1;
	}
}




template<typename T>
void DoublyLinkedList<T>::pop_front()
{
	
	if(tail==nullptr)
		{
			return;
		}
		if(head==tail)
		{
			Node<T>*temp=head;
			this->head=nullptr;
			this->tail=nullptr;
			delete temp;
			sz=sz-1;
		}
		else
        {
			Node<T>*temp=head;
			this->head=temp->next;;
			head->prev=nullptr;
			delete temp;
			sz=sz-1;
		}
		
}




template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& src)////copy assignment
{
	if(this!= &src)
	{
		clear();
		Node<T>* current=src.head;
		while (current)
        {
            this->push_back(current->data);
            current = current->next;
		}
    }
	
	
	return *this;
}




template<typename T>
std::string DoublyLinkedList<T>::to_str() const
{
    std::stringstream os;
    const Node<T> *curr = head;
    os << std::endl << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    os << "head: " << head << std::endl;
    os << "tail: " << tail << std::endl;
    os << "  sz: " << sz << std::endl;
    os << std::setw(16) << "node" << std::setw(16) << "node.prev" << std::setw(16) << "node.data" <<  std::setw(16) << "node.next" << std::endl;
    while (curr) {
        os << std::setw(16) << curr;
        os << std::setw(16) << curr->prev;
        os << std::setw(16) << curr->data;
        os << std::setw(16) << curr->next;
        os << std::endl;
        curr = curr->next;
    }
    os << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    return os.str();
}





//////////////////////////////////////////////////////////////////////////////
//                     helper template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
bool operator==(DoublyLinkedList<T> const& lhs, DoublyLinkedList<T> const& rhs)
{
    // getting you started on this once... definition for this overloaded operator will go here.
	Node<T>* left=lhs.head;
	Node<T>* right=rhs.head;
	if(lhs.size()== rhs.size())
	{
		for(int i=0;i<lhs.size();i++)
		{
			if(left->data!=right->data){
				return false;
			}
			else{
				left=left->next;
				right=right->next;
			}
			
		}
	return true;
	}
	return false;
}




template<typename T> 
bool operator!=(DoublyLinkedList<T> const&lhs, DoublyLinkedList<T> const&rhs)
{
	return !(lhs==rhs);
}




template<typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T> const& rhs)
{
    os << rhs.to_str();
    return os;
}

#endif
