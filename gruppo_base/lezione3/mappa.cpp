#include <bits/stdc++.h>

#define LIMIT 101
#define INF 1000000000

using namespace std;

int N;
char m[LIMIT][LIMIT];
int d[LIMIT][LIMIT];

bool isValid(int r, int c) // ritorna true se la cella e' dentro la matrice
{
	if (r < 0 || c < 0 || r >= N || c >= N)
		return false;
	return true;
}

void walk(int r, int c)
{
	// questi 2 array rappresentano le 8 direzioni in cui posso andare
	int ar[] = {-1,-1,0,1,1,1,0,-1}; // array righe (es. -1 significa vai nella riga sopra)
	int ac[] = {0,-1,-1,-1,0,1,1,1}; // array colonne (es. 1 significa vai verso destra)

	for(int i=0; i < 8; i++) // vai in una delle 8 direzioni
	{
		int new_row = r + ar[i];
		int new_col = c + ac[i];

		// se e' valida, non e' una trappola e la raggiungo con una distanza minore di quella con cui ci sono arrivato prima
		if (isValid(new_row, new_col) && m[new_row][new_col] == '*' && d[r][c]+1 < d[new_row][new_col])
		{
			d[new_row][new_col] = d[r][c] + 1; // aggiorno il numero di passi che servono per arrivarci
			walk(new_row, new_col); // ci vado dentro
		}
	}
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;
	
	for(int i=0; i < N; i++)
	{
		in.get(); // leggo il carattere 'a capo' (cioe' '\n')
		for(int j=0; j < N; j++)
		{
			m[i][j] = in.get();
			d[i][j] = INF;
		}
	}

	d[0][0] = 1;
	walk(0,0);
	
	out << d[N-1][N-1];

	out.close();
	in.close();
	return EXIT_SUCCESS;
}
