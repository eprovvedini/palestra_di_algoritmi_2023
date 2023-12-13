#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;

int vet[55];
int n;
int m[MAX];
int j=0;

void ric(int pos, int tot, int prec) {
	if(tot==0) { //non ho più soldi
		for(int i=0;i<pos;i++,j++) { //salvo la combinazione nel vettore principale
			m[j] = vet[i];
		}
		m[j] = INT_MAX; //uso INT_MAX come separatore
		j++;
	} else { //se ho ancora soldi
		for(int i=1;i<=prec;i++) {
			if(tot-i>=0) {
				vet[pos]=i;
				ric(pos+1,tot-i,i);
			} else {
				break;
			}
		}
	}
}

int main () {
    ifstream in ("input.txt");
    ofstream out("output.txt");
	in >> n;
	
	ric(0,n,n);
	
	for(int i=0;i<j;i++) {
	    if(m[i]==INT_MAX)
	        out << "\n";
	    else
	        out << m[i] << " ";
	}
	
	in.close();
	out.close();
	return 0;
}
