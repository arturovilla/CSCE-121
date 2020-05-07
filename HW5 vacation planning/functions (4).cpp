#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;


int readPrefs(char fileName[], int ngames, int prefs[])
{
  ifstream file;
  int gID = 0;
  int gspassed = 0;
  int rating = 0;
    
  file.open(fileName);

  if(!file.is_open())
  {
    return -1;
  }
for(int i = 0; i < ngames; i++)
{
  prefs[i] = 0;
}
  while(!file.eof())
  {
    file >> gID;
    file >> rating;
    if((gID > 0 && gID < 100) && (rating >= 0 && rating <= 5))
    {
      prefs[gID] = rating;
      gspassed += 1;
    }else{
      prefs[gID] = 0;
        
    }
      
  }

    return gspassed;
  }


int readPlan(char fileName[], int ngames, int plan[])
{
    int day = 0;
    
    int pval = 0;
    
  ifstream file;
  file.open(fileName);

  if(!file.is_open())
  {
    return -1;
  }

  while(!file.eof())
  {
    file >> day;
    file >> pval;
    plan[day] = pval;
      
  }

return 0;
}

int computeFunLevel (int start, int duration, int prefs[],int ngames, int plan[])
{
  int sum = 0;
  if((start + duration) > 366)// checks if date is in range
  {
    return -1;
  }
  else
  {
    for(int i = start; i < start+duration; i++)
    {
      int tempidx = plan[i];
      sum += prefs[tempidx];
    }
    return sum;}
}

int findBestVacation (int duration, int prefs[], int ngames, int plan[])
{
  int hfl = 0;
  int sd = 0;
  int x = 0;

  for(int i= 1; i<=365; i++)
  {
    x = computeFunLevel(i,duration,prefs ,ngames,plan);
    if(x>hfl)
    {
      hfl = x;
      sd = i;
    }
      
  }
  return(sd);
}
