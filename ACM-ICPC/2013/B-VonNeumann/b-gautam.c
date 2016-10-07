#include <stdio.h>

int main() {

	int N, numcases; scanf("%d", &numcases);
	double D, A, B, F, ans;
	while (numcases--) {
		scanf("%d %lf %lf %lf %lf", &N, &D, &A, &B, &F);
		ans = (F * D) / (A + B);	
		printf("%d %.2lf\n", N, ans);
	}
}

/*
Confession - I looked at the judge's solution on how to do this
The judge did not bother with infinite series, he or she 
just used distance = rate * time. He calculates the time that it took for
the bicycles to collide, which is D / (A + B) and then multiplies the 
fly's speed to get the total distance the fly went.
I tried too hard to solve this using infinte series.
*/
