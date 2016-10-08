#include <stdio.h>

int main() {

	int numcases; scanf("%d", &numcases);
	while (numcases--) {
		int casenum, n, s1, s2, s3;
		scanf("%d %d", &casenum, &n);
		s1 = (n*(n+1))/2;
		s2 = n*n;
		s3 = n*(n+1);
		printf("%d %d %d %d\n", casenum, s1, s2, s3);
	}

	return 0;
}

/*
 - Sum of first n integers is n(n+1)/2
 - Sum of first n odd integers is n^2
 - Sum of first n even integers is n^2 + n 
*/ 
