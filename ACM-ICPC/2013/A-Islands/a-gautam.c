#include <stdio.h> 

int main() {
	
	int numcases, casenum, arr[15];
	scanf("%d", &numcases);
	while (numcases--) {	
		int ans = 0;
		int* a = arr;
		scanf("%d %d", &casenum, a);
		for (a = arr+1; a != arr+15 ; a++) {
			scanf("%d", a);
			if (*a > *(a-1)) {
				ans++;
			}
		}
		
		printf("%d %d\n", casenum, ans);
	
	}
	return 0;
}

/* Idea
- Each island begins with a consecutive increase (a[i-1] < a[i]) and ends with a consecutive decrease (a[i-1] > a[i])
- Every Consecutive increase is a beginning of an island, and every consecutive decrease is an end of an island
- Exception to above (or so I thought) 
	- If there is a decrease at the beginning before any increases
	- If there is a increase at the end after any decreases
- But the first and last character is always 0, so the exceptions above will never be encountered
- Therefore, the number of islands is the number of consecutive increases, which is also the number of consecutive decreases.
*/
