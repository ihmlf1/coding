#include <iostream>
#include<cmath>
#include<vector>
bool judgeprime(long long int);
using namespace std;
int main() {
	int prime;
	while (cin>>prime) {
		bool check = false;
		if (prime % 2 == 1) {
			if (!judgeprime(prime - 2)) {
				cout << prime<<" is not the sum of two primes!" << endl;
			}
			else {
				cout << prime<<" is the sum of 2 and "<<prime-2<<"." << endl;
			}
		}
		else {
			long long up = prime / 2 - 1, down = prime / 2 + 1;
			for (;up>2||down<prime-2;up--,down++) {
				if (judgeprime(up)&& judgeprime(down)) {
					check = true;
					break;
				}
			}
			if (check) {
				cout << prime << " is the sum of "<<up<<" and " << down << "." << endl;
			}
			else {
				cout << prime << " is not the sum of two primes!" << endl;
			}
		}
	}
}
bool judgeprime(long long int in) {
	if (in <= 1)
		return false;
	for (short i = 2;i<=sqrt(in);i++) {
		if (in%i == 0)
			return false;
	}
	return true;
}


