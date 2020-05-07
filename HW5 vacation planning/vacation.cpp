#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

int main(){
    int a = 0;
    int b = 0;
    int c = 0;
  int games;
  int vacationDays;
    int prefs[MAX_NB_GAMES];
    int plan[366];
    char  gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE];
  string titles, preferences, planfile;

  cout << "Please enter ngames and duration: ";
  cin >> games;
  cin >> vacationDays;


  if((games > 200 || games <= 0) || (vacationDays >= 366 || vacationDays <= 0)) // checks if any values are out range
  {
    cout << "Invalid input.";
    //return(1);
      exit(0);
  }
//  int prefs[MAX_NB_GAMES];
//  int plan[366];
//  char  gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE];
  cout << "Please enter name of file with titles: ";
  cin >> titles;
  cout << "Please enter name of file with preferences: ";
  cin >> preferences;
  cout << "Please enter name of file with plan: ";
  cin >> planfile;


  a = readPrefs(const_cast<char*>(preferences.c_str()), games, prefs);
  b = readPlan(const_cast<char*>(planfile.c_str()), games, plan);
  c = readGameTitles(const_cast<char*>(titles.c_str()), games, gameTitles);
  if( a == -1 || b == -1 || c == -1)
  {
    cout << "Invalid file.";
    //return(1);
      exit(0);
  }
int k = findBestVacation (vacationDays, prefs, games , plan);
cout << "Best start day is " << k << endl;
cout << "Games to be played: " << endl;
printGamesPlayedInVacation(k, vacationDays, plan, gameTitles, games);


}
