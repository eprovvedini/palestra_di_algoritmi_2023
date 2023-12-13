#include <bits/stdc++.h>
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out("output.txt");
	
	map <int,int> m;
	int n,k;
	
	in >> k >> n;
	
	for(int i=0;i<n;i++) {
		int da,a;
		in >> da >> a;
		m[da]=max(m[da],a);
	}
	
	int att=m[0];
	int cont=1;
	
	while(att!=k-1) {
		int prox=att;
		for(auto &coppia : m) {
			if(coppia.first<=att+1) {
				if(coppia.second>prox) {
					prox=coppia.second;
				}
			} else
				break;
		}
		att=prox;
		cont++;
	}
	
	out << cont;
	
	in.close();
	out.close();
	return 0;
}