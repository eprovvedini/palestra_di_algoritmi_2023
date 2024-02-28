#include <bits/stdc++.h>
using namespace std;

int main () {
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	/*
	In un parco avventura ci sono N alberi
	Tra questi alberi sono tirate M carrucole (ogni carrucola collega due alberi)
	Per una tempesta alcuni alberi sono stati abbattuti
	Per ogni albero abbattuto crollano le carrucole collegate ad esso
	Si vuole sapere quante carrucole sono rimaste
	*/
	
	int N, M; //Numero iniziale di alberi e carrucole
	set <int> s; //Set degli alberi ancora in piedi
	
	in >> N >> M;
	
	for(int i=0; i<N ; i++) {
		int b;
		in >> b;
		if(b==1) { 			//Se l'albero è ancora in piedi
			s.insert(i);	//Lo inserisco nel set
		}
	}
	
	int count=0; //Conto il numero di carrucole rimaste
	
	for(int i=0; i<M; i++) {	//Per ogni carrucola
		int da, a;
		in >> da >> a;		//Prendo i due alberi a cui è collegata
		if(s.count(da) && s.count(a))	//Se i due alberi sono ancora in piedi
			count++;					//Allora anche la carrucola c'è ancora
	}
	
	out << count;
	
	in.close();
	out.close();
	
	return 0;
}
