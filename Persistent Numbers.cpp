#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main() {
	int in,temp;
	while (cin>>in&&in!=-1) {
		vector<vector<int> >out(10);
		unsigned short first = 0,min= USHRT_MAX,num;
		for (short i=9,temp=in;i>0;i--,temp=in) {
			if (temp%i == 0) {
				vector<int>te;
				for (short j = i; j > 1&&temp!=0; j--) {
					while (temp%j == 0) {
						te.push_back(j);
						temp /= j;
						if (temp <=1) {
							te.push_back(temp);
							break;
						}
					}
				}
				if (temp<10&&temp==1) {
					out[first].insert(out[first].begin(),te.begin(),te.end());
					if (min>out[first].size()&&out[first].size()!=0) {
						min = out[first].size();
						num = first;
					}
					first++;
				}
			}
		}
		if (min!= USHRT_MAX) {
			for (short end=in<10?out[num].size()-1: out[num].size()-2;end>=0;end--) {
				cout << out[num][end];
			}
			cout << endl;
		}
		else if(in<=1){
			cout << "1"<<in << endl;
		}
		else {
			cout << "There is no such number." << endl;
		}
	}
}




