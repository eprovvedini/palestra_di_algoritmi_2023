#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

/*
William sta giocando a Super Marco 64
Ci sono alcune piattaforme collegate tra loro da ponti
Su ogni piattaforma ci possono essere delle monete
Andando sulla piattaforma si raccolgono tutte le monete su di essa
William parte dalla piattaforma 0
Calcola quante monete può raccogliere al massimo
*/

vector <vector <int> > v; 	//Grafo delle piattaforme
int monete[MAX];			//Monete per piattaforma
int piattaforme, collegamenti, somma=0;

int ric(int p);

int main () {
	ifstream in ("input.txt");
	ofstream out("output.txt");
	
	in >> piattaforme >> collegamenti; //Num piattaforme e collegamenti
	
	for(int i=0; i<piattaforme; i++) {
		in >> monete[i];				//Num di monete sulla piattaforma i
	}
	
	v.assign(piattaforme,vector <int> ()); //Inizializzazione grafo
	
	for(int i=0; i<collegamenti; i++) {		//Aggiungo gli archi al grafo
		int da, a;
		in >> da >> a;
		v[da].push_back(a);					//Gli archi sono bidirezionali
		v[a].push_back(da);					//Quindi aggiungo in entrambe le direzioni
	}
	
	ric(0);									//Attraverso il grafo con una ricorsione partendo dalla piattaforma 0
	
	out << somma;
	
	in.close();
	out.close();
	return 0;
}

int ric(int p) {		//p = piattaforma attuale
	somma+=monete[p];	//Raccolto tutte le monete sulla piattaforma
	monete[p]=-1;		//Ora su quella piattaforma non ci sono più monete
	for(int i=0;i<v[p].size();i++) {	//Per ogni piattaforma raggiungibile da p
		if(monete[v[p][i]]!=-1) {		//Se ha ancora monete (quindi non l'ho ancora visitata)
			ric(v[p][i]);				//Ci vado
		}
	}
}
