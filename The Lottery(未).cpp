#include<iostream>
#include<vector>
using namespace std;
int main() {
	unsigned int all, chose;
	while (cin>>all>>chose) {
		int temp=1;
		vector<int>choseone,participate;
		for (short i=0;i<chose;i++) {
			cin >> temp;
			choseone.push_back(temp);
		}
		unsigned total = 0;
		for (unsigned j = 1; j <= all; j++) {
			bool check = true;
			for (vector<int>::iterator be=choseone.begin();be!=choseone.end();be++) {
				if (j%(*be)==0) {
					check = false;
					break;
				}
			}
			if (check) {
				total++;
			}
		}
		cout << total << endl;
	}
}


