#include <bits/stdc++.h>
#define MAX 10005
#define INF LLONG_MAX
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out("output.txt");
	
	long long n,m,src,dst;
	vector <vector<pair<long long,long long>>> g;
	long long int dist[MAX];
	queue <long long> q;
	
	in >> n >> m >> src >> dst;
	
	src--;
	dst--;
	
	g.assign(n, vector<pair<long long,long long>>());
	
	for(long long i=0;i<m;i++) {
		long long da,a,p;
		in >> da >> a >> p;
		da--;
		a--;
		g[da].push_back(make_pair(a,p));
	}
	
	for(int i=0;i<n;i++) {
		dist[i]=INF;
	}
	
	dist[src]=0;
	q.push(src);
	
	while(!q.empty()) {
		int att=q.front();
		q.pop();
		for(int i=0;i<g[att].size();i++) {
			int nodo=g[att][i].first;
			int d=g[att][i].second;
			if(dist[nodo]>dist[att]+d) {
				dist[nodo]=dist[att]+d;
				q.push(nodo);
			}
		}
	}
	
	out << dist[dst];
	
	in.close();
	out.close();
	return 0;
}
