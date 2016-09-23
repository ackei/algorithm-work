// Untested - Produced Output for input.in
#include <stdio.h>

int main() {

	int numcases; 
	scanf("%d", &numcases);
	while (numcases--) {
		int num, ans = 1, in;
		scanf("%d %d", &num, &in);
		
		while (in != 1) {
			if (in > ans) { ans = in; }
			if ((in & 1)) {
				in = (in << 1) + in + 1;
			}
			else {
				in = (in >> 1);
			} 
		}		

		printf("%d %d\n", num, ans);
	}	

	return 0;
}
