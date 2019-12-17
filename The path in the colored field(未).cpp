#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<map>
#include<cmath>
using namespace std;
int main() {
	unsigned short length;
	while (cin>>length) {
		string temp;
		short te;
		map<short,short> one,three;
		for (short y = 0; y < length; y++) {
			cin >> temp;
			for (short x = 0; x < length; x++) {
				te = temp[x] - '0';
				if (te == 1) {
					one.insert(pair<short,short>(x+y,y));
				}
				else if (te==3) {
					three.insert(pair<short, short>(x+y, y));
				}
			}
		}
		vector<unsigned int>distance;
		for (map<short, short>::iterator it=one.begin();it!=one.end();it++) {
			unsigned int min=UINT_MAX;
			for (map<short, short>::iterator thr = three.begin(); thr != three.end(); thr++) {
				if (min> abs((long double)((*it).first - (*it).second) - ((*thr).first - (*thr).second)) + abs((long double)(*it).second - (*thr).second)) {
					min = abs((long double)((*it).first - (*it).second) - ((*thr).first - (*thr).second)) + abs((long double)(*it).second - (*thr).second);
				}
			}
			distance.push_back(min);
		}
		unsigned int max = 0;
		for (vector<unsigned int>::iterator be=distance.begin();be!=distance.end();be++) {
			if (max < (*be)) {
				max = (*be);
			}
		}
		cout << max << endl;
	}
}

