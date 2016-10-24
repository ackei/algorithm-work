#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

ull memo[35];

ull numcomp(int n, int m, int k){
	if (n <= 0)
		return 1;
	if (memo[n])
		return memo[n];
	ull answer = 0;
	int j;
	for (j = 0; j < n; j++){
		if ((k == 0 && m == n-j) || (k && (n-j-m+k) % k == 0))
			continue;
		answer += numcomp(j,m,k);
	}
	return memo[n] = answer;
}

int main(){
	int TC, c, n, m, k;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d %d %d %d",&c,&n,&m,&k);
		memset(memo,0,sizeof memo);
		printf("%d %llu\n",c,numcomp(n,m,k));
	}
	return 0;
}
