#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	int N;
	int g,goal;
	int i;
	
	in >> N;
	
	int vet[MAX];
	
	for(i=0;i<MAX;i++) {
		vet[i]=0;
	}
	
	for (i=0;i<N;i++) {
		in >> g;
		in >> goal;
		vet[g]+=goal;
	}
	
	int c=0;
	int goalc=0;
	for(i=0;i<MAX;i++) {
		if (vet[i]>goalc) {
			goalc=vet[i];
			c=i;
		}
	}
	
	out << c << " " << goalc;
	
	return 0;
	
}