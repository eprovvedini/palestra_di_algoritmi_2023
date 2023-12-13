#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int n;
int panini[MAX];
int dp[MAX];
int soluzione;

int walk(int ind){
	if(dp[ind]>0)
		return dp[ind];
	int best = 0;
	for(int i = ind+2;i<n;i++) {
		if(panini[i]>=panini[ind]) {
			best = max(best, walk(i));
		}
	}
	best+=1;
	dp[ind] = best;
	
	soluzione = max(soluzione, best);
	
	return best;
}

int main () {
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	in >> n;
	for(int i=0;i<n;i++) {
		in >> panini[i];
	}
	
	for(int i=0;i<n;i++) {
		walk(i);
	}
	out << soluzione;
	
	in.close();
	out.close();
	return 0;
}