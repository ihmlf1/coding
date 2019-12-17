#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	unsigned int number=1;
	string temp;
	while (getline(cin,temp,'#')) {
		map<string,int>out;
		for (int current = 0, after;current!=temp.npos;current++) {
			after = temp.find_first_of(" \n", current);
			if (after == -1) {
				break;
			}
			if (out.find(temp.substr(current, after - current)) == out.end()) {
				out.insert(pair<string, int>(temp.substr(current, after - current), 0));
			}
			else {
				(*out.find(temp.substr(current, after - current))).second++;
			}
			current = after;
		}
		cout << "Set #"<<number<<":"<<endl;
		for (map<string,int>::iterator be=out.begin();be!=out.end();be++) {
			if((*be).first!="")
			cout << (*be).first <<" "<< (*be).second+1<< endl;
		}
		cout << endl;
		number++;
	}
}


