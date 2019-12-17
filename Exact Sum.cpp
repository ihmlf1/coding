#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<climits>
using namespace std;
int main() {
	int number,temp,money;
	while (cin >> number) {
		map<int, int>books;
		while (number--) {
			cin >> temp;
			if (books.find(temp) != books.end()) {
				(books.find(temp))->second++;
			}
			else {
				books.insert(pair<int, int>(temp, 0));
			}
		}
		int min = 9000000,temp1,temp2;
		cin >> money;
		for (map<int, int>::iterator a=books.begin(); a!=books.end();a++) {
			for (map<int, int>::iterator b=books.begin(); b!=books.end(); b++) {
				if ((*a).first + (*b).first == money && min > (*a).first - (*b).first) {
					if (a != b || (*a).second >= 1) {
						temp1 = (*a).first;
						temp2 = (*b).first;
						min = abs((double)(*a).first - (*b).first);
					}
				}
			}
		}
		cout << "Peter should buy books whose prices are "<<temp1<<" and "<<temp2<<".\n" << endl;
	}
}

