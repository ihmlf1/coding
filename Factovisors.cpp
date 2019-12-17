#include <iostream>
#include<cstdlib>
#include<cmath>
#include<map>
using namespace std;
void factor(long long*,map<long long,long long>*);
int main() {
	long long n, devide;
	while (cin>>n>>devide) {
		long long tempa = devide;
		bool can=true;
		map<long long, long long>  first,de;
		factor(&devide,&de);
		for (map<long long, long long>::iterator bede = de.begin();bede!=de.end()||can; bede++) {
			if (bede == de.end()) {
				break;
			}
			if (first.find((*bede).first) == first.end()) {
				if ((*bede).first == 1)
					continue;
				if ((*bede).first>n) {
					can = false;
					break;
				}
				else {
					short total = -1;
					for (long long i = (*bede).first, a = i, b = i; i <= n; i+=b,a=i) {
						while (a% (*bede).first==0) {
							total++;
							a /= (*bede).first;
						}
						if (total>= (*bede).second) {
							break;
						}
						if (i == n)
							can = false;
					}
				}
			}
		}
		if (can)
			cout << tempa << " divides " << n << "!" << endl;
		else
			cout << tempa << " does not divides " << n << "!" << endl;
	}
}
void factor(long long* in, map<long long, long long>* ma) {
	short i = 2;
	while (i<=sqrt(*in)) {
		while (*in%i==0) {
			if ((*ma).find(i)==(*ma).end()) {
				(*ma).insert(pair<long long,long long>(i,0));
			}
			else {
				((*ma).find(i))->second++;
			}
			*in /= i;
		}
		i++;
	}
	if ((*ma).find(*in) == (*ma).end()) {
		(*ma).insert(pair<long long, long long>(*in, 0));
	}
	else {
		((*ma).find(*in))->second++;
	}
}

