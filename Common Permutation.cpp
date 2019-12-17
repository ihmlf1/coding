#include<iostream>
#include<string>
#include<map>
using namespace std;
unsigned short howmany(string , char);
int main() {
	string a, b;
	while (getline(cin,a)&&getline(cin,b)) {
		map<char, int>out;
		for (unsigned short i = 0;i<a.size();i++) {
			for (unsigned short j = 0;j<b.size();j++) {
				if (a[i]==b[j]&& out.find(a[i]) == out.end() &&isalpha(a[i])&&isalpha(b[j])){
					unsigned short min = howmany(a, a[i]) < howmany(b, a[i])?howmany(a,a[i]):howmany(b,a[i]);
					out.insert(pair<char,int>(a[i],min));
					break;
				}
			}
		}
		for (map<char, int>::iterator be = out.begin(); be != out.end(); be++) {
			for (;(*be).second>0;(*be).second--) {
				cout << (*be).first;
			}
		}
		cout << endl;
	}
}
inline unsigned short howmany(string in,char check) {
	unsigned short min = 0;
	for (unsigned short i=0;i<in.size();i++) {
		if (in[i]==check) {
			min++;
		}
	}
	return min;
}




