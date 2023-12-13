#include<bits/stdc++.h>
#include <map>
using namespace std;

int main (){
	map <int, char> mappa;
	mappa[2] = 'a';
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	int N, i, num;
	int p1, p2, d1, d2;
	p1 = p2 = d1 = d2 = -1;
	
	in >> N;
	
	for(i=0;i<N;i++) {
		in >> num;
		if (num%2==0) {
			if(num>p1) {
				p2 = p1;
				p1 = num;
			} else if(num>p2) {
				p2 = num;
			}
		} else {
			if(num>d1) {
				d2 = d1;
				d1 = num;
			} else if(num>d2) {
				d2 = num;
			}
		}
	}
	
	int ris1 = -1;
	int ris2 = -1;
	
	if(p1!=-1 && p2!=-1) {
		ris1 = p1+p2;
	}
	if(d1!=-1 && d2!=-1) {
		ris2 = d1+d2;
	}
		
	int ris = ris1;
		
	if(ris1>ris2){
		ris = ris1;
	} else {
		ris = ris2;
	}
		
	out << ris;

	return 0;
}
