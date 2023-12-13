#include <bits/stdc++.h>
#define MAX 100005
#define MAX2 501
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out("output.txt");

	bitset<MAX> bs;
	int m[MAX2][MAX2];
	
	bs.set();
	bs[1]=false;

	for(long long i=2; i < MAX; i++) {
		if (bs[i]) {
			for(long long j=i*i; j < MAX; j+=i) {
				bs[j] = false;
			}
		}
	}
	
	int r,c;
	
	in >> r >> c;
	
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			int temp;
			in >> temp;
			int z;
			for(z=temp;!bs[z] && z<=MAX;z++) {}
			m[i][j]=z-temp;
		}
	}
	
	int minimo=INT_MAX;
	
	//controllo riga con valore minore
	for(int i=0;i<r;i++) {
		int somma=0;
		for(int j=0;j<c;j++) {
			somma+=m[i][j];
		}
		minimo=min(somma,minimo);
	}
	
	//controllo colonna con valore minore
	for(int i=0;i<c;i++) {
		int somma=0;
		for(int j=0;j<r;j++) {
			somma+=m[j][i];
		}
		minimo=min(somma,minimo);
	}
	
	out << minimo;
	
	in.close();
	out.close();
	return 0;
}
