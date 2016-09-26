#include <cstdio>
#include <cstring>

typedef unsigned long long ull;

ull answer[21][21];

ull euler_zigzag(int n, int k){
	if (n == 1 && k == 1)
		return 1;
	if (k >= n || k < 1)
		return 0;
	if (answer[n][k] > 0)
		return answer[n][k];
	return answer[n][k] = euler_zigzag(n,k-1) + euler_zigzag(n-1,n-k);
}

int main(){
	memset(answer,0,sizeof answer);
	
	for (int i = 2; i <= 21; i++){
		ull sum = 0;
		for (int j = 1; j <= i; j++)
			sum += euler_zigzag(i,j);
		printf("%d %llu\n",i-1,(i==2) ? sum : sum*2);
	}

	return 0;
}
