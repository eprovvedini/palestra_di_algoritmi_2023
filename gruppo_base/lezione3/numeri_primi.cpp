#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int N;
	bool vet[MAX];
	
	cin >> N;
	
	for(int i=2;i<N;i++) {
		if(vet[i] == false) {
			int j = i;
			while(j<=N) {
				j+=i;
				vet[j] = true;
			}
		}
	}
	
	if(vet[N] == false) {
		cout << N << " e' primo!";
	} else {
		cout << N << " non e' primo!";
	}
	
	/*for(int i=0;i<N;i++) {
		if(!vet[i]) {
			cout << i << " ";
		}
	}*/

	in.close();
	out.close();
	return 0;
}

