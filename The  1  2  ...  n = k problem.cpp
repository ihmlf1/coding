#include <iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main() {
	long long in, i;
	cin >> i;
	while (i--) {
		cin >> in;
		long long total = 0;
		while (total*(total + 1) / 2 <= abs(in) || (total*(total + 1) / 2 - (abs(in))) % 2 == 1) {
			if (in == 1) {
				total = 1;
				break;
			}
			total++;
		}
		cout << total << endl;
		if (i)
			cout << "\n";
	}
}


