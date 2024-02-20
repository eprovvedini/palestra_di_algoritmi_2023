#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int N,D,M;
    int c[MAX];
    
    //Ci sono N appendini, con costo c[i]
	//Ci sono M clienti
	//Quando arriva un cliente, vuole usare l'appendino meno costoso
	//Se non ci sono appendini, il proprietario paga una penale di D
	//Calcolare profitto della serata
    
    in >> N >> D; //N appendini, D multa
    
    for(int i=0; i<N; i++)
        in >> c[i]; //Costi degli appendini
        
    in >> M;		//Clienti della serata
        
    sort(c, c+N); //Ordino i costi in modo crescente (quando un cliente arriva, usa il meno costoso)
    
    int profitto=0; //Inizializzo il profitto a 0
    
    for(int i=0; i<M; i++) {		//Per ogni cliente
        if(i<N)					//Se ci sono ancora appendini liberi
            profitto += vet[i]; //Guadagno
        else					//Altrimenti
            profitto -= D;		//Pago la multa
    }
    
    out << profitto;
    
    return 0;
}
