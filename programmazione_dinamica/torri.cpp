#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	int altezze[MAX],costo[MAX],appoggio[MAX];
	int torri,i,costo_tot=0,j;
	
	in >> torri;
	
	for(i=0;i<torri;i++) {
		in >> altezze[i];
		in >> costo[i];
		costo_tot+=costo[i];
	}
	
	appoggio[torri-1]=costo[torri-1];
	
	for(i=torri-2;i>=0;i--) {
		appoggio[i]=costo[i];
		for(j=i+1;j<torri;j++) {
			if(altezze[j]<altezze[i]) {
				appoggio[i]=max(appoggio[i],costo[i]+appoggio[j]);
			}	
		}
	}
	
	int massimo=0;
	
	for(i=0;i<torri;i++)
		massimo=max(massimo,appoggio[i]);
		
	out << costo_tot-massimo;
	
	in.close();
	out.close();
	return 0;
}