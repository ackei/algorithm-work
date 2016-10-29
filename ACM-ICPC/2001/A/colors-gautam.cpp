#include <iostream>
using namespace std;


const int N = 16;
int r[N], g[N], b[N];

int distsq(int i, int* r, int* g, int* b, int rv, int gv, int bv) {
	
	return (r[i] - rv)*(r[i] - rv) + (g[i] - gv)*(g[i] - gv) + (b[i] - bv)*(b[i] - bv);
}



int main() {

	for (int i = 0; i < N; i++) {
		cin >> r[i] >> g[i] >> b[i]; 
	}
	
	int rv,gv,bv;
	cin >> rv >> gv >> bv;
	while ((rv != -1) or (gv != -1) or (bv != -1)) {
		
		int ans = 0;
		for (int i = 1; i < N; i++) {
			if (distsq(ans,r,g,b,rv,gv,bv) > distsq(i,r,g,b,rv,gv,bv) ) {
				ans = i;
			}
		}
		
		cout << "("<< rv << "," << gv << "," << bv << ") maps to (" << r[ans] << "," << g[ans] << "," << b[ans] << ")" << endl;  
		cin >> rv >> gv >> bv;
	}


	return 0;
}
