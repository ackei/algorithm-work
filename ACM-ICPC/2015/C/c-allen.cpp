#include <cstdio>
#include <cstring>

typedef unsigned long long ull;

void mat_mul(ull a[][2], ull b[][2]){
	ull prod[2][2];
	memset(prod,0,sizeof prod);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				prod[i][j] += a[i][k] * b[k][j];
	memcpy(a,prod,sizeof prod);
}

void mat_exp_mod(ull ans[][2], ull mat[][2], ull pow, ull mod){
	while (pow){
		if ((pow & 1) == 1)
			mat_mul(ans,mat);
		mat_mul(mat,mat);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				mat[i][j] %= mod, ans[i][j] %= mod;
		pow = pow >> 1;
	}
}

ull fib(ull n){
	ull ans[2][2] = {{1,0},{0,1}};
	ull fib_mat[2][2] = {{1,1},{1,0}};
	mat_exp_mod(ans,fib_mat,n,1000000000);
	return ans[0][1];
}

int main(){
	int TC, c;
	ull n;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d %llu",&c,&n);
		printf("%d %llu\n",c++,fib(n));
	}
	return 0;
}
