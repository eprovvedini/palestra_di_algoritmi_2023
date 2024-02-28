#include <bits/stdc++.h>
#define MAX 100
using namespace std;

/*
Ugo ama viaggiare in treno, quindi vuole viaggiare il pi� a lungo possibile.
Deve viaggiare per N giorni.
Ogni giorno pu� decidere se prendere un treno della compagnia A o della compagnia B o non viaggiare
Ugo pu� prendere un treno B solo se il giorno prima non ha viaggiato
(Quindi pu� prendere un treno B il primo giorno)
Hai la durata del viaggio per ogni societ� ogni giorno
Calcola il tempo massimo che pu� viaggiare Ugo
*/

int tempo_massimo (int N, int A[], int B[]) {
	int dp[MAX];
	
	dp[0] = 0;
	dp[1] = max(A[0], B[0]);
	
	for(int i=2; i<=N; i++) {
		dp[i] = max(dp[i-1]+A[i-1], dp[i-2]+B[i-1]);
	}

	return dp[N];
}

int main(){
	int n = 4;
	int a[4] = {3,3,3,3};
	int b[4] = {2,3,1,4};
	
	cout << tempo_massimo(n, a, b);
}
