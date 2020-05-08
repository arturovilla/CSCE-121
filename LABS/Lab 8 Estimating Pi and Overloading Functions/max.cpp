int max(int a, int b){
	if(a>b){return a;}
	else {return b;}
}
double max(double a, double b){
	if(a>b){return a;}
	else {return b;}
}
int min(int a, int b){
	if(a<b){return a;}
	else {return b;}
}
char max(char a, char b){
	if(a>b){return a;}
	else{return b;}
}
int* max(int*a, int n, int*b, int m){
const int t=min(n, m);
int *rlist = new int [t];
//int list[t];
for(int k=0; k<t; ++k){
	if((a[k]>b[k]) || (a[k]==b[k])){rlist[k]=a[k];}
		else {rlist[k]=b[k];}
}
if(n>t){for(int j=0;j<n-t;++j){
	rlist[t+j]=a[t+j];
}
}
if(m>t){for(int j=0;j<m-t;++j){
	rlist[t+j]=b[t+j];
}
}
return rlist;
}
char* max(char* a, char* b){
for(int i=0; i<255; ++i){
	int l=std::toupper(a[i]);
	int k=std::toupper(b[i]);
	if (l>k){return a;}
	else{return b;}
}
}
int max(int a, int b, int c, int d, int e, int f){
	int currbest=a;
	if(currbest<b){currbest=b;}
	if(currbest<c){currbest=c;}
	if(currbest<d){currbest=d;}
	if(currbest<e){currbest=e;}
	if(currbest<f){currbest=f;}
	return currbest;
}