#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int M, C, prices[21][21], answers[201][21];

int shop(int remaining, int garment){
	if (remaining < 0)
		return -1000000;
	if (garment == C)
		return M - remaining;
	if (answers[remaining][garment] != -1)
		return answers[remaining][garment];

	int max_spent = -1;
	for (int i = 1; i <= prices[garment][0]; i++)
		max_spent = max(max_spent, shop(remaining-prices[garment][i],garment+1));

	return answers[remaining][garment] = max_spent;
}

void print_shop(int remaining, int g){
	if (remaining < 0 || g == C) return;
	for (int i = 1; i <= prices[g][0]; i++){
		if (shop(remaining-prices[g][i],g+1) == answers[remaining][g]){
			printf("Garment %d: $%d\n",g,prices[g][i]);
			print_shop(remaining-prices[g][i],g+1);
			break;
		}
	}
}

int main(){
	int TC, i, j;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d %d",&M,&C);
		memset(answers,-1,sizeof answers);
		for (i = 0; i < C; i++){
			scanf("%d",&prices[i][0]);
			for (j = 1; j <= prices[i][0]; j++)
				scanf("%d",&prices[i][j]);
		}
		int ans = shop(M,0);
		//print_shop(M,0);
		if (ans < 0)
			printf("%s\n","no solution");
		else
			printf("%d\n",ans);
	}
	return 0;
}

