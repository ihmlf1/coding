#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int main() {
	unsigned short number;
	cin >> number;
	map<unsigned long long, unsigned long long>pr;
	for (short m = 9;m>=2;m--) {
		pr.insert(pair<unsigned long long, unsigned long long>(m, 0));
	}
	for (unsigned short i=0;i<number;i++) {
		bool check = false;
		unsigned long long in;
		cin >> in;
		while (in>1) {
			for (map<unsigned long long, unsigned long long>::reverse_iterator it=pr.rbegin();it!=pr.rend();it++) {
				while (in%(*it).first==0&&in!=1) {
					in /= (*it).first;
					(*it).second++;
				}
			}
			if (in == 1) {
				check = true;
			}
			else {
				break;
			}
		}
		if (in <= 1&&!check) {
			cout << in << endl;
		}
		else if(check){
			for (map<unsigned long long, unsigned long long>::iterator it = pr.begin(); it != pr.end(); it++) {
				while ((*it).second>0) {
					cout << (*it).first;
					(*it).second--;
				}
			}
			cout << endl;
		}
		else {
			cout << "-1" << endl;
		}
		for (short m = 9; m >= 2; m--) {
			pr[m]=0;
		}
	}
}




