#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>&in,unsigned);
int main() {
	unsigned short innumber;
	while (cin>>innumber&&innumber!=0) {
		unsigned int total=0,temp;
		vector<int>out;
		cin >> temp;
		out.push_back(temp);
		for (unsigned i=0;i<innumber-1;i++) {
			cin >> temp;
			sort(out,temp);
		}
		while (out.size()>=2) {
			int te[2] = { out[0],out[1] };
			total = out[0]+ out[1]+total;
			out.erase(out.begin());
			out.erase(out.begin());
			sort(out, te[0]+te[1]);
		}
		cout << total << endl;
	}
}
void sort(vector<int> &in,unsigned a) {
	bool check = true;
	for (vector<int>::iterator begin=in.begin();begin!=in.end();begin++) {
		if (a<(*begin)) {
			check = false;
			in.insert(begin,a);
			break;
		}
	}
	if (check) {
		in.insert(in.end(),a);
	}
}




