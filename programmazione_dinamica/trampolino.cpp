#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int main () {
    ifstream in ("input.txt");
    ofstream out("output.txt");
    
    int n;
    int vet[MAX];
    
    in >> n;
    
    for(int i=0;i<n;i++) {
        in >> vet[i];
    }
    
    int indice=n;
    int cont=0;
    
    for(int i=n;i>0;) {
		int indN;
        for(int j=i-1;j>=0;j--) {
            if(vet[j]+j>=indice)
                indN=j;
        }
        i=indN;
        indice=indN;
        cont++;
    }
    
    out << cont;
    
    in.close();
    out.close();
    return 0;
}
