#include <iostream>
#include <string>
#include "Stack.h"
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;




/*
 
 cout<<"Enter filename: ";
 cin>>name;
 ifstream file(name);
 ///////////////////////
 if(file.fail()==true)
 {
 
 file.clear();
 cout<<"File can't be open."<<endl;
 goto finished;
 //continue;
 }
 
 while(file.eof()!=true && file.fail()!=true)
 {
 getline(file,line);
 std::size_t pos = line.find(",");
 
 line= line.substr(pos+1); //talk to ferrara
 
 // make a string variablew and keep adding leters to it on by one with a for loop
 then use a second for loop to coutthew elem,ents of the for loop with spaces inbetween them
 
 or you can use stacks
 */







int main() {
    Stack<string> result;
    
   
   
    
    string phrase;
    string word;
    //cout<<"enter a phrase: "<<endl;
    getline(cin, phrase );
    //cin>>wordtopush;
    //cout<<"current word: "<<phrase<<endl;
    //std::size_t pos = 0;
    size_t index = 0;
    size_t pos = 0;
    
    while(pos < phrase.length())
    {
        if(phrase.find(" ",index) == string::npos)
        {
            pos =  phrase.length();
        }
        else
        {
             pos =  phrase.find(" ",index); // index is where th find function is starting
        }
        
        word = phrase.substr(index,pos-index); //

        result.push(word);
        index = pos+1;
//        phrase = phrase.substr(index,phrase.length());
        //cout << ": " << result.peek() << endl;
//        cout << ": "<<phrase<<endl;
        //index = pos;
       
        
    }
    
    string firstword  = result.pop();
    firstword = firstword.substr(0,firstword.length()-1);
    cout<<firstword<<" "<<endl;
    while(result.size() > 0)
    {
        cout<<result.pop()<<" ";
    }

    return 0;
}
