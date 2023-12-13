#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > mat;
int n;
int ric(int i,int j);

int main () {
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	in >> n;
	
	mat.assign(n,vector <int> ());
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<=i;j++) {
			int da;
			in >> da;
			mat[i].push_back(da);
		}
	}
	
	out << ric(0,0);
	
	in.close();
	out.close();
	return 0;
}

int ric(int i, int j) {
	if(j>i || i>n-1)
		return 0;
	int ric1=ric(i+1,j);
	int ric2=ric(i+1,j+1);
	if(ric1>ric2)
		return ric1+mat[i][j];
	else
		return ric2+mat[i][j];
	return 0;
}
