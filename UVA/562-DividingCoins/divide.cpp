#include<cstdio>
#include<tuple>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int coins[100], m, memo[100][100*505];

int knapsack(int i, int C){
    if(C == 0) return 0;
    if(i == m) return 0;
    if(coins[i] > C) return knapsack(i+1, C);
    if(memo[i][C] != -1) return memo[i][C];
    int &ans = memo[i][C];
    ans = max(knapsack(i+1, C), coins[i] + knapsack(i+1, C-coins[i]));
    return ans;
}

int main(){

    int TC, ans, sum, sack;
    scanf(" %d", &TC);
    while(TC--){
        sum = 0;
        scanf(" %d", &m);
        fill(&memo[0][0], &memo[(m > 0) ? (m - 1) : 0][((m > 0) ? (m - 1) : 0)*504], -1);
        for(int i = 0; i < m; ++i){
            scanf(" %d", &coins[i]);
            sum += coins[i];
        }
        sack = knapsack(0, sum / 2);
        ans = abs(sum - 2*sack);

        printf("%d\n", ans);
    }

}
