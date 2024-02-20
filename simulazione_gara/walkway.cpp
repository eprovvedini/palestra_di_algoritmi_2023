#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	int N, K;
	int H[MAX];
	
	/*
	Un'attrazione di Gardaland consiste di N camere a diversa altezza
	H[i] = altezza della camera i
	Si vuole costruire una passerella scenografica che segua le stanze da fuori
	Almeno K camere devono essere visibili dalla passerella
	Date le altezze delle camere, trova l'insieme di K camere con differenza di altezza minore
	(stampa la differenza di altezza)
	Es: H = {1, 2, 7, 8, 3}, K = 3
	Soluzione = 2 (le camere sono quelle ad altezza 1, 2 e 3)
	*/
	
	in >> N >> K; //Numero camere, grandezza dell'insieme
	
	for (int i=0; i<N; i++) {
		in >> H[i]; 			//Altezze delle camere
	}
	
	sort (H, H+N);			//Ordino le camere per altezza
	
	int minore = H[K-1]-H[0];	//Differenza di altezza tra le prime K camere
	
	int i=0;
	
	for(int j=K-1; j<N; j++) {
		if (H[j]-H[i] < minore) //Se la finestra successiva ha una differenza minore
			minore = H[j]-H[i]; //Aggiorno
		i++;
	}
	
	out << minore;
	
	return 0;
}
