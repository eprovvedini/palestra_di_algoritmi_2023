#include <bits/stdc++.h>
#define MAX 300000
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	long long int punti[MAX];
	long long int n, c=1, i, i1;
	
	in >> n;
	
	for (i=0;i<MAX;i++) {
		punti[i]=0;
	}
	
	for (i=0;i<n;i++) {
		in>> punti[i];
	}
	
	sort (punti, punti+n);
	if (n>1) {
		i1=1;
		for (i=1;i<n;i++) {
			if (punti[i]==punti[i-1]) {
				i1=i1+c;
			}else {
				c++;
				i1=i1+c;
			}
		}
	}else {
		i1=c;
	}
	
	out<<i1;
	
	return 0;
}
