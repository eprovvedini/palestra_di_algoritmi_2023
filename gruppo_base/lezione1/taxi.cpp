#include <fstream>
using namespace std;

int main () {
	ifstream in ("input.txt");
	ofstream out("output.txt");
	int n,c,i,somma,cprec;
	
	in >> n;
	in >> somma;
	cprec=somma;
	
	for(i=1;i<n;i++) {
		in >> c;
		cprec++;
		if(cprec<c) {
			somma+=cprec;
		} else {
			somma+=c;
			cprec=c;
		}
	}
	
	out << somma;
	
	return 0;
}