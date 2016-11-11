#include <stdio.h>

int main(){
	unsigned long long fact[21];
	fact[0] = 1;
	for (int i = 1; i <= 20; i++){
		fact[i] = fact[i-1] * i;
	}

	unsigned long long C[21][21];
	for (int i = 0; i <= 20; i++){
		C[i][0] = C[i][i] = 1;
	}
	for (int n = 1; n < 20; n++){
		for (int m = 0; m < n; m++){
			C[n+1][m+1] = C[n][m] + C[n][m+1];
		}
	}
	int TC, c, n, k;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d %d %d",&c,&n,&k);
		if (k == 1){
			printf("%d %llu\n",c,fact[n-1]);
			continue;
		}
		unsigned long long num = 0;
		for (int i = 2; i <= k; i++){
			num += fact[n-i] * fact[i-1] * C[k-2][i-2];
		}
		printf("%d %llu\n",c,num);
	}
}
