#include<iostream>
using namespace std;
int main()
{
	unsigned long long in;
	while (cin>>in&&in!=0) {
		bool check=false;
		for (unsigned long long i=in,ti=i;!check;ti++,i=ti) {
			bool twoorthree = true;
			while (!check) {
				if (twoorthree) {
					if (i % 2 != 0) {
						twoorthree = false;
						continue;
					}
					i /= 2;
				}
				else {
					if (i==1) {
						cout << ti << endl;
						check = true;
						break;
					}
					if (i % 3 != 0 ) {
						break;
					}
					i /= 3;
				}
			}
		}

	}
	return 0;
}




