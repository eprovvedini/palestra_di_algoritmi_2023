#include <bits/stdc++.h>
#define MAX 300000
using namespace std;

int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    
    int n;
    vector<int> v;
    
    in >> n;
    
    for(int i=0;i<n;i++) {
        int temp;
        in >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int cont = 0;
    
    int somma = 0;
    int risparmio = 0;
    
    for(int i=n-1;i>=0;i--) {
        somma+=v[i];
        if(cont==2) {
            risparmio += v[i];
            cont = 0;
        } else {
            cont++;
        }
    }
    
    out << somma-risparmio;
    
    return 0;
}