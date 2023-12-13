#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out("output.txt");
	
	int n,i;
	int vet[MAX];
	char vet2[MAX];
	bool ok=false;
	
	in >> n;
	
	for(i=0;i<n-1;i++) {
		vet[i]=i+1;
		in >> vet2[i];
	}
	
	vet[i]=i+1;
	
	while(!ok) {
		ok=true;
		for(int i=0;i<n-1;i++) {
			if(vet2[i]=='<') {
				if(vet[i]>vet[i+1]) {
					int temp=vet[i];
					vet[i]=vet[i+1];
					vet[i+1]=temp;
					ok=false;
				}
			} else {
				if(vet[i]<vet[i+1]) {
					int temp=vet[i];
					vet[i]=vet[i+1];
					vet[i+1]=temp;
					ok=false;
				}
			}
		}
		//cout << "ciao";
	}
	
	for(i=0;i<n;i++)
		out << vet[i] << " ";
	
	in.close();
	out.close();
	return 0;
}