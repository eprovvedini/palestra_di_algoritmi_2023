#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >>n;
    int p[MAX];
    int g[MAX];
    
    for(int i=0;i<n;i++){
        in >> p[i];
    }
    for(int i=0;i<n;i++){
        in >> g[i];
    }
    
    int attuale = p[0];//30
    long long int ris = attuale*g[0];//150
    for(int i=1;i<n;i++) {
		if(p[i]<attuale)
			attuale=p[i];
		ris+=attuale*g[i];
	}
    
    out << ris;
}