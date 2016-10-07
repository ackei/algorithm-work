#include <cstdio>

int main(){
	int T, K, C, S, count = 1;
	scanf("%d",&T);
	while (T--){
		scanf("%d %d %d",&K,&C,&S);
		bool check_all = false;
		if (C == 1 || K == 1)
			check_all = true;
		bool possible = true;
		if ((check_all && S < K) || (S < K - 1))
			possible = false;
		printf("Case #%d: ", count++);
		if (!possible)
			printf("IMPOSSIBLE");
		else{
			if (check_all){
				for (int i = 1; i <= K; i++)
					printf("%d ",i);
			}
			else{
				for (int i = 2; i <= K; i++)
					printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}
