#include <bits/stdc++.h>
using namespace std;

bool salti[2][100001];

int n, m;

vector <vector <int>> grafo;

int nodi_raggiunti;

void walk(int nodo_attuale, int volo);

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  in >> n >> m;

  for(int i = 0; i < n; i++) {
    salti[0][i] = false;
    salti[1][i] = false;
  }

  grafo.assign(n + 1, vector<int>());

  for(int i = 0; i < m; i++) {
    int da, a;
    in >> da >> a;

    grafo[da].push_back(a);
  }

  nodi_raggiunti = 0;
  walk(0, 0);

  out << nodi_raggiunti;

  return 0;
}

void walk(int nodo_attuale, int volo) {
  //cerr << nodo_attuale << " " << volo << " " << salti[(volo + 1) % 2][nodo_attuale] << "\n";
  if(!(volo % 2)) {
    nodi_raggiunti++;
  }

  salti[volo % 2][nodo_attuale] = true;

  for(int i = 0; i < grafo[nodo_attuale].size(); i++) {
    if(!salti[(volo + 1) % 2][grafo[nodo_attuale][i]] && nodi_raggiunti != n) {
      walk(grafo[nodo_attuale][i], volo + 1);
    }
  }
}
