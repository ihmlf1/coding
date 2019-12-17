#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main() {
	short ca;
	cin >> ca;
	for (short w = 0;w<ca;w++) {
		string temp;
		cin >> temp;
		unsigned long long total =1;
		map<char, int>out;
		for (int i = 0; i < temp.size(); i++) {
			if (out.find(temp[i]) == out.end()) {
				out.insert(pair<char, int>(temp[i], 1));
			}
			else {
				(*out.find(temp[i])).second++;
			}
		}
		for (unsigned long long i=2;i<temp.size()+1;i++) {
			total *= i;
			for (map<char, int>::iterator be=out.begin();be!=out.end();be++) {
				while ((*be).second>1&&total%(*be).second==0) {
					total /=(*be).second;
					(*be).second--;
				}
			}
		}
		cout << "Data set " << w+1 << ": " << total << endl;
	}
}




