#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    string a;
    int count = 0; 	//numero di quasi-isogrammi totali
    int v[MAX]; 	//vettore per contare quante volte compare un carattere
    getline(in,a);	//prendo in input una riga
    int n = stoi(a);
    
    for(int i=0;i<30;i++) {
        v[i]=0;
    }
    
    for(int i=0;i<n;i++) {
        string s;
        getline(in,s);
        
        bool ok = true;
        
        int l = s.size();
        
        for(int j=0;j<l && ok;j++) {
            if(isalpha(s[j])) {
                s[j] = toupper(s[j]);
                int c = s[j] - 'A';
                if(v[c]==2) {
                    ok = false;
                } else {
                    v[c]++;
                }
            }
        }
        if(ok)
            count++;
        for(int i=0;i<30;i++) {
        	v[i]=0;
    	}
    }
    out << count;
    in.close();
    out.close();
}
