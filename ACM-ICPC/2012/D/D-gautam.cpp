#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	int x; cin >> x;
	while (x--) {
		int turn, numstep;
		register int count, j, k;
		double  p, q, r;
		cin >> turn; cin >> numstep; cin >> p; cin >> r;
		q = 1 - p - r;
		int choices = 2*numstep + 1;
		
		double arr[choices][numstep+1][2];

		for (count = 0; count < 1; count++) {
			for (k = 0; k <= numstep; k++) {
				for (j = 0 ; j < choices; j++) {
					arr[j][k][count] = 0;
				}
			}
		} 

		arr[-1 + 1][0][0] = p;
		arr[0 + 1][0][0] = q;
		arr[1 + 1][1][0] = r;		

		for (count = 1; count < numstep; count++) {
			for (k = 0; k <= numstep; k++) {
				for (j = -numstep; j <= numstep; j++) {
					if (j < k) {
						arr[j + numstep][k][count&1] = 
							  p*arr[j + 1 + numstep][k][(count-1)&1]
							+ q*arr[j + numstep][k][(count-1)&1]
							+ r*arr[j - 1 + numstep][k][(count-1)&1];
					}
					else if (j == k){	
						arr[j + numstep][k][count&1] = 
							 q*arr[j + numstep][k][(count-1)&1]
							+ r*arr[j - 1 + numstep][k][(count-1)&1]
							+ r*arr[j - 1 + numstep][k-1][(count-1)&1];			 				  }
				}
			}
		}


		double ans;
		for (int k = 0; k <= numstep; k++) {
			double term = 0;
			for (int j = -numstep; j <= numstep; j++) {
				term += arr[j + numstep][k][(numstep-1)&1];		
			}
			ans += k*term;
		}

		cout << turn << " " << setprecision(5) << ans << endl;
	}

	return 0;
}
