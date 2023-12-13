#include <bits/stdc++.h>
using namespace std;

int quadri(int N, long long M, int V[]) {
    int n = N;
    long long m = M;
    
	int b = 0, i = 0;
	long long somma = 0LL;

	while(((somma + V[i]) <= m) && (i < n)) {
		somma += (long long)V[i];
		++i, ++b;
	}

	for(; i < n; ++i) {
		if(V[i] > m) 
			return 0;
			
		somma += (long long)V[i] - V[i - b];
		while(somma > m) {
		     --b;
		     somma -= (long long)V[i - b];
		}
			 
	}

	return b;
}