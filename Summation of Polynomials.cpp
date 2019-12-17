#include <iostream>
using namespace std;
int main() {
	int in;
	while (cin>>in) {
		unsigned long long end = 0;
		end = in* (in + 1)/2;
		end *= end;
		cout << end/2 << endl;
	}
}


