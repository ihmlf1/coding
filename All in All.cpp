#include <iostream>
#include<string>
using namespace std;
int main() {
	string in, ina;
	while(cin >> in >> ina) {
		string::size_type position= ina.find(in[0]);
		bool end = position==ina.npos?false:true;
		for (int i=1;i<in.size();i++) {
			if (ina.find(in[i], position+1) == ina.npos || ina.find(in[i],position+1) < position||position==ina.size()-1) {
				end = false;
				break;
			}
			else {
				position = ina.find(in[i], position+1);
			}
		}
		if (end) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}



