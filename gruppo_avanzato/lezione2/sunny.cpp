#include <bits/stdc++.h>
#define MAX_NODI 50001
#define MAX_PESO 50001

using namespace std;

vector<vector<pair<int, int> > > g; // ogni coppia rappresenta un arco {vicino, peso dell'arco}
bool visitato[MAX_NODI];

int sol = -1;
int nodi, archi, nodo_inizio, nodo_fine;

void walk(int nodo, int num_passi) {
	if (nodo == nodo_fine) {// sono arrivato alla fine, mi salvo la soluzione
		sol = num_passi;
		return;
	}

	if (visitato[nodo]) {
		/* la ragazza sceglie sempre la galleria meno illuminata.
		Se sono gia' passato da un nodo significa che verranno ripetute le stesse scelte,
		quindi si creera' un loop infinito: non esiste soluzione.*/
		return;
	}
	
	visitato[nodo] = true;

	//ora devo vedere chi, tra i vicini di questo nodo, ha l'arco col peso piu' basso

	int arco_minimo = -1;
	int peso_minimo = MAX_PESO;
	for(int i=0; i < g[nodo].size(); i++)
	{
		int vicino = g[nodo][i].first;
		int peso = g[nodo][i].second;

		if (peso < peso_minimo)
		{
			peso_minimo = peso;
			arco_minimo = vicino;
		}
	}

	walk(arco_minimo, num_passi+1); // aumento il numero di passi che ho fatto
}

int main()
{
	for(int i=0; i < MAX_NODI; i++) // setto tutti i nodi come non visitati
		visitato[i] = false;

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> nodi >> archi >> nodo_inizio >> nodo_fine;

	g.assign(nodi+1, vector<pair<int, int> >()); // inizializzo tutti i nodi senza vicini
	
	for(int i=0; i < archi; i++)
	{
		int da, a, peso;
		in >> da >> a >> peso;

		g[da].push_back({a, peso}); // aggiungo un vicino al nodo da con il suo corrispondente peso
		g[a].push_back({da, peso}); // grafo non orientato, aggiungo anche l'arco di ritorno (che ovviamente ha lo stesso peso)
	}

	walk(nodo_inizio, 0); // parto dal nodo di inizio avendo fatto 0 passi
	out << sol << "\n";

	in.close();
	out.close();
	return 0;
}
