#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int n, t;
	in >> n >> t;
	
	int x;
	in >> x;
	bool ok = true;
	int ris = -1;
	
	for(int i=1;i<n && ok;i++) {
		int a,b;
		in >> a >> b;
		int s1 = 24-a;
		int s = s1+b;
		if(s>=t) {
			ok = false;
			ris = i-1;
		}
	}
	
	out << ris;

	in.close();
	out.close();
	return 0;
}
