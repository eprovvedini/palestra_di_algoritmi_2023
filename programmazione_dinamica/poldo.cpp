#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out("output.txt");
	
	int a[MAX],p[MAX]={0};
	int n,i,j;
	
	in >> n;
	
	for(i=0;i<n;i++) {
		in >> a[i];
	}
	
	p[n-1]=1;
	
	for(i=n-2;i>=0;i--) {
		for(j=i+1;j<n;j++) {
			if(a[i]>a[j])
				p[i]=max(p[i],p[j]);
		}
		p[i]++;
	}
	
	int massimo=0;
	
	for(i=0;i<n;i++) {
		massimo=max(massimo,p[i]);
	}
	
	out << massimo;
	
	in.close();
	out.close();
	return 0;
}