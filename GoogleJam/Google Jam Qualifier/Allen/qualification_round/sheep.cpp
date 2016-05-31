#include <cstdio>

int count(int N){
	if (!N)
		return -1;
	int ans, tmp, used = 0;
	for (int i = 1; used != (1<<10) - 1; i++){
		ans = tmp = i*N;
		while (tmp) { 
			used |= 1 << (tmp % 10); 
			tmp /= 10; 
		}
		if (used == (1<<10) - 1)
			return ans;
	}
}

int main(){
	int TC,c = 1;
	scanf("%d",&TC);
	while (TC--){
		int N;
		scanf("%d",&N);
		int num = count(N);
		if (num < 0)
			printf("Case #%d: INSOMNIA\n",c++);
		else
			printf("Case #%d: %d\n",c++,num);
	}
}