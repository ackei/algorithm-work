#include <cstdio>
#include <cstring>

unsigned long long memo[105][10005][20];

unsigned long long partition(unsigned long long m, unsigned long long n, int cap){
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (memo[m][n][cap])
		return memo[m][n][cap];
	unsigned long long ans = 0;
	unsigned long long i = 1;
	long long exp = 0;
	while (exp <= cap){
		if (n < i)
			break;
		ans += (partition(m,n-i,exp));
		i *= m;
		exp++;
	}
	return memo[m][n][cap] = ans;
}

int main(){
	int TC, c;
	unsigned long long m, n;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d %llu %llu",&c,&m,&n);
		memset(memo,0,sizeof memo);
		printf("%d %llu\n", c, partition(m,n,15));
	}
	return 0;
}
