#include<iostream>
#include<cmath>
#include<map>
using namespace std;
bool square(int);
int main() {
	int number;
	while (cin>>number) {
		bool check = false;
		map<int,int>divisor;
		for (int i=1;i<=sqrt(abs((double)number));i++) {
			if (number%i==0) {
				divisor.insert(pair<int,int>(i,number/i));
			}
		}
		int bigout, smallout;
		for (map<int, int>::iterator be=divisor.begin();be!=divisor.end();be++) {
			if (((*be).first+(*be).second)%2==0) {
				bigout = ((*be).first + (*be).second) / 2;
				smallout =((*be).second - (*be).first)/2;
				check = true;
				break;
			}
		}
		if (check) {
			cout << bigout<<" " <<smallout<< endl;
		}
		else if (number%2==1) {
			cout << "Spinster Number." << endl;
		}
		else {
			cout << "Bachelor Number." << endl;
		}
	}
}
inline bool square(int in) {
	if (in == (int)sqrt(in)*(int)sqrt(in)) {
		return true;
	}
	return false;
}

