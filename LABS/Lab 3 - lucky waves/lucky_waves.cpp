#include <iostream>
using namespace std;
int main() {
	double n = 0;
	double currentWave = 0;
	// double nextWave = 0;
	double i = 0;
	double currentNum = 0;
	double nextNum = 0;
	int bestWave = 0;
	// cout << "number of numbers";
	cin >> n;
	// cout << endl;
	for (i = 0; i < n; ++i) {
			// cout << "next number ";
			cin >> nextNum;
			if (nextNum > currentNum) {currentWave += 1;}
			if (currentWave > bestWave) {bestWave = currentWave;}
			if (nextNum < currentNum) {currentWave = 0; currentWave += 1;}
			// else {currentWave=0;}
			currentNum = nextNum;
			// nextWave += 1;
			// cout << currentWave << " current wave" << endl;
	}
	cout << bestWave;
}