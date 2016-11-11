#include <stdio.h>

int r(int n, int m){
	if (n < 0 || m < 0 || m > n)
		return 0;
	if (m == 0 || m == n)
		return 1;
	return (n-m) * m + 1;
}

int main(){
	int TC, c, n, m;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d %d %d",&c,&n,&m);
		printf("%d %d\n",c,r(n,m));
	}
	return 0;
}
