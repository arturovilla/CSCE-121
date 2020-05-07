#include <iostream>
#include "functions.h"
using namespace std;
int main(){
	char LeftTeamName[255];
	char RightTeamName[255];
	unsigned int noParticipants;
	double leftTeam[200];
	double rightTeam[200];
	double totRight=0, totLeft=0;
	
	cin>>noParticipants;
	cin>>LeftTeamName;
	cin>>RightTeamName;
	//validForces(leftTeam, noParticipants)
	readForceValuesFromStdIn(leftTeam, rightTeam, noParticipants);
	bool LEFT = validForces(leftTeam, noParticipants);
	bool RIGHT = validForces(rightTeam, noParticipants);
	
	if((LEFT==false) && (RIGHT==false)){cout<<"both teams have an invalid force!"<<endl;return 1;} 
	else if (LEFT==false && RIGHT==true){cout<<LeftTeamName<<" has an invalid force!"<<endl;return 1;}
	else if (RIGHT==false && LEFT==true){cout<<RightTeamName<<" has an invalid force!"<<endl;return 1;}
	
	double netForce{calculateForce(leftTeam,rightTeam, noParticipants)};
	printWinnerToStdOut(LeftTeamName,RightTeamName,netForce);
	
	return 0;
}