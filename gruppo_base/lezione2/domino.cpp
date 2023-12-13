#include <bits/stdc++.h>
using namespace std;

int N;

struct tessera{
    int s,d;
};

tessera t[10];
tessera r[10];
bool usata[10];
tessera permutazione[10];
int lunghezza = 0;

void trova_permutazione(int pos) {
    if (pos > lunghezza)
        lunghezza = pos;
    for (int i = 0; i < N; i++) {
        if (pos == 0 || (permutazione[pos-1].d == t[i].s && usata[i] == false)) {
            permutazione[pos] = t[i];
            usata[i] = true;
            trova_permutazione(pos + 1);
            usata[i] = false;
        }
        if (pos == 0 || (permutazione[pos-1].d == r[i].s && usata[i] == false)) {
            permutazione[pos] = r[i];
            usata[i] = true;
            trova_permutazione(pos + 1);
            usata[i] = false;
        }
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    for(int i = 0; i < N; i++)
    {
        in >> t[i].s >> t[i].d;
        r[i].s = t[i].d;
        r[i].d = t[i].s;
    }
    for(int i = 0; i < N; i++)
        usata[i] = false;
    
    trova_permutazione(0);
    out << lunghezza;
    return 0;
}