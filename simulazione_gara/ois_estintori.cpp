#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int r,c;
char m[MAX][MAX];

bool controllaCamera(int x, int y);

/*
Abbiamo una mappa di un edificio, con la seguente legenda:
- muri identificati da #
- stanze identificate da .
- estintori identificati da @
Bisogna capire in quante stanze non ci sono estintori
*/

int main () {
	ifstream in ("input.txt");
	ofstream out("output.txt");
	
	int cont = 0;	//Num stanze senza estintori
	
	in >> r >> c; 	//Num righe e num colonne della mappa
	
	//Input della mappa
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			in >> m[i][j];
		}
	}
	
	//Controllo della mappa
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(m[i][j]=='.' || m[i][j]=='@') 	//se sono entrato in una camera
				if(!controllaCamera(i,j))	 	//Se la stanza non ha estintori
					cont++;						//Aumento il conteggio stanze senza estintori
		}
	}
	
	out << cont;
	
	in.close();
	out.close();
	return 0;
}

bool controllaCamera(int x, int y) {
	bool ris = false;				//Assumo non ci siano estintori
	for(int i=x; m[i][y]=='.' || m[i][y]=='@'; i++) { 	//Fin quando sono nella stanza, verticalmente
		for(int j=y;m[i][j]=='.' || m[i][j]=='@';j++) { //Fin quando sono nella stanza, orizzontalmente
			if(m[i][j]=='@')							//Se c'è un estintore
				ris=true;								//Cambio la risposta
			m[i][j]='#';								//Metto un muro al posto della stanza, per non tornarci
		}
	}
	return ris;											//Ritorno la risposta (true se ci sono estintori)
}
