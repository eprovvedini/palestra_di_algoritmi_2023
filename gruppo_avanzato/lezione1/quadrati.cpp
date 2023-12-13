#include <bits/stdc++.h>
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	long int a,b;
	long int x,y;
	long int n;
	
	in >> a >> b;
	
	x=sqrt(b);
	y=sqrt(a);
	if (y*y!=a)
	   n=x-y;
	else
	    n=x-y+1;
 	   
 	out << n;
	
	return 0;
}