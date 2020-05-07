#include <iostream>
#include <string>
using namespace std;

#include "functions.h"



/* readTweet
 * Parameters:
 *      line: string containing the tweet information received by the function
 *      isRetweet: reference to bool; function will update it with true if retweet
 *      nb_htags: reference to int; function will update with number of hashtags
 *                in the tweet.
 *      array_of_htags: reference to an array of strings; function will allocate
 *                      the array and store the hashtag in it
 * Return value:
 *      none
 * Functionality:
 *     Processes the string in order to find out hashtags and identify if it is Retweet
 */
void readTweet(string line, bool& isRetweet,int& nb_htags, string*& array_of_htags)
{
   
    string hashtag;
    int idx;
    
    int oldnumhash = nb_htags;
    int counter =oldnumhash;
    ///////////////////////////////////////////1st for loop
    for(int i =0; i<line.length(); i++)
    {
        if(line[i] =='#')
        {
            nb_htags++;
        }
    }
    
    if(line.find("RT")!= string::npos)/// this finds wheather or not it is a retweet
    {
        isRetweet=true;
    }
    
    string *newarry = new string[nb_htags]; //coopy the old date
    
    // copy stuff from the old array
    for(int i =0; i<oldnumhash; i++)
    {
        newarry[i] = array_of_htags[i];
    }
    
    
    for(int i =0; i<line.length(); i++)// 2nd for loop
    {
        if(line[i] =='#')
        {
            idx=i;
            
            for(int j = idx+1;j< line.length(); j++)
            {
                if(line[j] != '\0' && line[j] !=' ' && line[j] !='#' && line[j] != '.' && line[j]!='"') //talk to ferrera
                {
                   
                    hashtag+=tolower(line[j]);
                    
                }
                else if(line[j] == '\0' || line[j] == ' ' || line[j] =='#' || line[j] == '.' || line[j]=='"')
                {
                    break;
                }
            }
            
            
           // cout<<hashtag<<endl;
            newarry[counter] = hashtag; // counter + old number of (hastags-
            hashtag = "";
           // cout << "counter: " << counter << endl;
            //cout << "hashtage: " << hashtag << endl;
            counter++;
            
           
        }
    }
    
    delete [] array_of_htags;
    array_of_htags = newarry;
    
}

/* insertHashtag
 * Parameters:
 *      ht: string
 *      hashlist: reference to OrderedHashtagList struct
 * Return value:
 *      true if insertion succeeds, false if memory allocation
 *      fails.
 * Functionality:
 *      the function searches for the string ht in the hashlist’s array. If the hashtag is already in the list, its counter is updated and the order of the elements in the array may need to be rearranged if the increment of the popularity counter changes the ordering of the hashtags.
 If the hashtag is not in the list, it needs to be inserted. If there is no capacity in the array, a resize to double its capacity must be carried out.
 In order to account for #TAMU and #tamu as the same hashtag, hashtags in the hashlist must be all in lowercase. The Useful functions section discusses the library support std::tolower and other methods that you may find useful when manipulating the string ht.
 */

bool insertHashtag(string ht, OrderedHashtagList& hashlist)
{
    OrderedHashtagList newhashlist;
    
    if(hashlist.capacity ==1 && hashlist.size==0)// this is for the very first pass through this will not happen if the hashlist already has data inside
    {
        newhashlist.list[0].name = ht;
        newhashlist.list[0].counter+=1;
        newhashlist.size++;
        //// restet old hashlist and return as this will never happen after the first go
        hashlist.size = newhashlist.size;
        hashlist.capacity = newhashlist.capacity;
        delete [] hashlist.list;
        hashlist.list = newhashlist.list;
        //cout<<"old hashlist capacity: "<<hashlist.capacity<<" old hashlist size: "<<hashlist.size<<" new hashlist capacity: "<<newhashlist.capacity<<" new hashlist size: "<<newhashlist.size<<endl;//debug purposes
        return true;
        
    }
    
    //cout<<"old hashlist capacity: "<<hashlist.capacity<<" old hashlist size: "<<hashlist.size<<" new hashlist capacity: "<<newhashlist.capacity<<" new hashlist size: "<<newhashlist.size<<endl; // debug purposes
    
    for(int i =0;i<newhashlist.capacity;i++)
    {
        if(hashlist.size==hashlist.capacity)// on the second pass it will be
        {
            Hashtag* hashtagarry = new Hashtag[hashlist.capacity+1]; // you have to resize the data
            for(int j = 0; j< hashlist.capacity; j++ )// copy old data
            {
                hashtagarry[j].name = hashlist.list[j].name;
                hashtagarry[j].counter = hashlist.list[j].counter;
            }
            delete [] hashlist.list;
            hashlist.list = hashtagarry; // here there new array is resized and has all the old data
            hashlist.capacity+=1;
        }
        //now lets say it doesnt need a resize or it was just resizeed and now we need to check if the lists hvae the same or diff name and if the same we need to increa the counter
        // within the for loop we are already in  all we need to is write
        if(hashlist.list[i].name == ht)
        {
            hashlist.list[i].counter+=1;
            return true;
        }
        
        
        
    }
    hashlist.list[hashlist.capacity-1].name=ht;//this is when there is an entirly new hashtag
    hashlist.list[hashlist.capacity-1].counter+=1;
    hashlist.size++;
    
    
    
    
    
    
    
    
    
    
    
     return true;

    
    
    
}
/* showMostPopularHashtags
 * Parameters:
 *      hashlist: reference to OrderedHashtagList struct
 * Return value:
 *      none
 * Functionality:
 *      Prints the k most popular hashtags.
 *      See prompt for formatting details.
 */
void showMostPopularHashtags(OrderedHashtagList hashlist, int k)
{
    //string d;
    
    //chack if there are k element s
    
    

    
    /*
     Tag #aggieland - 1 occurrence(s)
     Tag #gigem - 1 occurrence(s)
     Tag #aggienetwork - 1 occurrence(s)
     Tag #sec - 1 occurrence(s)
     */
    if(k>10)
    {
        //bexit(1);
        k=10;
    }
    
    for(int i =0;i<k; i++)
    {
        //d=<hashlist.list[i];
        cout<<"Tag #"<<hashlist.list[i].name<<" - "<<hashlist.list[i].counter<<" occurrence(s)"<<endl;// the number of unique hastags
        
    }
    //cout << "To be implemented by the student" << endl;
}


