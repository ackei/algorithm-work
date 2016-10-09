#include <stdio.h>

int main() {

	int i, j, pas[51][52];
	pas[0][0] = pas[1][0] = pas[1][1] = 1;	
	for (i = 2; i <= 50; i++) {
		pas[i][0] = 1;
		for (j = 1; j < i; j++) { 
			pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
		}
		pas[i][i] = 1;
	}

	int numcases; scanf("%d", &numcases);
	
	while (numcases--) {

		int numcases, Ntimes2, N, kmax, kmin, k = 0;
		long long ans = 0;
		scanf("%d %d", &numcases, &Ntimes2);
		N = Ntimes2 / 2;
		kmax = N / 2;
		kmin = N%3 ? ((N/3) + 1) : (N / 3);
		for (k = kmin;	k <= kmax; k++) {
			ans += ((long long)pas[N-k][k]*(long long)pas[N-k][k]);
		}
		printf("%d %lld\n", numcases, ans);

	}

	return 0;
}

/*
 - We know that total number of steps is 2*N, where N is the total number of steps taken by each foot (left and right).
 - Consider just one foot.
 - Let k be the number of double steps taken. Then the number of single steps taken must be n - 2k.
 - The number of strides taken is (k) + (n - 2k) = n-k.
 - The maximum number of double steps cannot exceed N/2, because N/2 double steps means N steps. Therefore, kmax is floor(N/2).
 - The minimum number of double steps, given the criteria of the problem, should follow k > n - 2k  or 3k > n. So, kmin is ceil(N/3);
 - Now, given a k, we now have a number of double steps and and single steps.
	- To find out the ordering, we find out all permutations. That is Comb(N-k, k) = (N - k)! / (N - 2k)!(k)!
	- To account for both feet, we any permutation for the right foot can be interweaved with any permutation for the left foot, so we square.
	- Ans(N) = sum from k = ceil(N/3) to floor(N/2) Comb(N-k,k)^2 
*/
