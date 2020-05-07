#include <iostream>
#include <cmath>
#include "functions.h"
using namespace std;
void readForceValuesFromStdIn(double* leftTeam, double* rightTeam, unsigned const int noParticipants){
	for (unsigned int i=0; i<noParticipants; ++i){
	cin>>leftTeam[i]>>rightTeam[i];
	}
}
void printWinnerToStdOut(const char* leftTeamName, const char* rightTeamName, const double netForce){
if (netForce<-5)
	{cout<<rightTeamName<<" wins!\n";}
	
else if (netForce>5)
	{cout<<leftTeamName<<" wins!\n";}

else
	{cout<<"Tie.\n";}
	}
	
double calculateForce(const double* leftTeam, const double* rightTeam, unsigned const int noParticipants){
	double totLeft=0;
	double totRight=0;
	for (unsigned int i=0; i<noParticipants; ++i){
		totLeft +=leftTeam[i];
		totRight +=rightTeam[i];
	}
	return totLeft-totRight;
}
bool validForces(const double* forces, unsigned const int noParticipants){
	for(unsigned int i=0; i<noParticipants; ++i){
		if (forces[i]<0)
			{return false;}
	}		
	return true;

}
