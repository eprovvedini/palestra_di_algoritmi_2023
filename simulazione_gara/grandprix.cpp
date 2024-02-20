#include <bits/stdc++.h>
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	/*
	State assistendo a un Gran Premio di Formula 1.
	Ogni auto ha associato un numero.
	Potete vedere sul tabellone l'ordine di partenza delle auto.
	Ogni volta che un'auto sorpassa un'altra sul tabellone appaiono due numeri:
	- chi ha fatto il sorpasso
	- chi è stato sorpassato
	Capire che auto arriva per prima
	*/
	
	int n,m,a1,a2;
	
	int N, M;
	int A1; A2;
	
	in >> N >> M; //Numero di auto e numero di sorpassi
		
	int primo;
	
	in >> primo;  //L'unica auto che ci interessa salvare è quella in prima posizione
	
	for(int i=0; i<N; i++) {
		int x;
		in >> x;	//Possiamo scartare le altre
	}
	
	for(int i=0; i<M; i++) {  //Per ogni sorpasso
		in >> A1 >> A2;
		if(A2==primo)		//Se l'auto sorpassata è la prima in classifica
			primo=A1;		//Aggiorno il primo in classifica
	}
	
	out << primo;
	
	in.close();
	out.close();
	return 0;
}
