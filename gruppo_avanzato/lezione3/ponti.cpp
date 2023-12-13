#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out("output.txt");
	
	bool visitato[MAX];
	int n,m;
	vector <vector<int>> g;
	
	in >> n >> m;
	
	g.assign(n,vector<int>());
	
	for(int i=0;i<m;i++) {
		int da,a;
		in >> da >> a;
		g[da].push_back(a);
		g[a].push_back(da);
	}
	
	for(int i=0;i<n;i++) {
		visitato[i]=false;
	}
	
	int visitati=0;
	int cont=0;
	
	while(visitati!=n) {
		int indice;
		for(int i=0;i<n;i++) {
			if(!visitato[i]) {
				indice=i;
				visitato[i]=true;
				visitati++;
				break;
			}
		}
		queue <int> q;
		q.push(indice);
		while(!q.empty()) {
			int att=q.front();
			q.pop();
			for(int j=0;j<g[att].size();j++) {
				int nodo=g[att][j];
				if(!visitato[nodo]) {
					visitato[nodo]=true;
					visitati++;
					q.push(nodo);
				}
			}
		}
		cont++;
	}
	
	out << cont-1;
	
	in.close();
	out.close();
	return 0;
}