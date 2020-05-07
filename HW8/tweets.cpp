#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "functions.h"

/* Starter code: used by function printMenu */
void printLine(string msg)
{
    cout << msg << endl;
}

/* Starter code: function printMenu() is ready for you */
void printMenu()
{
    cout << endl;
    printLine("Welcome to Aggieland Twitter Feeds Stats");
    printLine("The options are:");
    printLine("1. load tweet data file and update stats");
    printLine("2. show overall stats (number of tweets, retweets, and hashtags)");
    printLine("3. show most popular hashtags");
    printLine("9. quit");
    cout << "--------> Enter your option: ";
}

/* Starter code: function to read option from the user is ready for you */
int getOption()
{
    int option;
    cin >> option;
    if (cin.fail())
    {
	cin.clear();
	cin.ignore(256, '\n');
	return -1;
    }
    else
    {
	cin.ignore(256, '\n');
    }
    return option;
}


/*  if the pick 2  we need to output :
 Tweets: 3, Retweets: 2, Hashtags: 5
 if they pcik 3
 Tag #aggieland - 1 occurrence(s)
 Tag #gigem - 1 occurrence(s)
 Tag #aggienetwork - 1 occurrence(s)
 Tag #sec - 1 occurrence(s)
 
 */


int main()
{
    printMenu();
    int userinput;
    userinput = getOption();
    /////////////////////////////////////
    bool isRetweet = false;
    int nb_hatags =0;
    string *array_of_htags= new string[0];
    string line;
    string name;
    int retweetcntr = 0;
    int tweetcntr = 0;
    
    //Hashtag currenttag;
    OrderedHashtagList listofhashes;
    //Hashtag* arrayofhashtags = new Hashtag[1];
    /////////////////////////////////////////////////////////////////////////////////
    
    
    
    
    while(userinput==1 ||userinput==2 ||userinput==3 )
    {
        if(userinput==1)//we get the file name and the extension csv or tx
        {
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
                //cout<<pos+2<<endl;
                //////////////////////
                readTweet(line, isRetweet, nb_hatags, array_of_htags);
                if(isRetweet==true)
                {
                    retweetcntr++;
                    isRetweet=false;
                }
                tweetcntr++;
                if(line=="")
                {
                    tweetcntr--;
                }
            }
            
            for(int i = 0 ; i<nb_hatags; i++)
            {
                insertHashtag(array_of_htags[i], listofhashes);
            }
        }
        
        //////////////////////////////////////////////////////////////////////////////////////////////nohashtag.txt
        else if(userinput == 2)
        {
            cout<<"Tweets: "<<tweetcntr<<", Retweets: "<<retweetcntr<<", Hashtags: "<<listofhashes.size<<endl;
        }
        //////////////////////////////////////////////////////////////////////////////////////////////
        else if(userinput == 3)
        {
            if(listofhashes.size==0)
            {
                cout<<"No hashtags."<<endl;
                goto finished;
                
            }
            int k  = listofhashes.size;
            showMostPopularHashtags(listofhashes, k);
        }
       ///////////////////////////////////////////////////////////////////////////////////////////////
    finished:
        printMenu();
        userinput = getOption();
    }
    
    if(userinput!=9)
    {
        cout<<"Invalid option"<<endl;
        goto finished;
    }
    else
    {
        return 0;
    }
    return 0;
}
   
    
