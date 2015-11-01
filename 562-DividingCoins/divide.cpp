#include<cstdio>
#include<tuple>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int coins[100], m, memo[100][100];

int computeSplit(int i, int j){
    if(i == j) return coins[i];
    if(memo[i][j] != -1) return memo[i][j];
    int i_k, k_j;
    int &ans = memo[i][j] = 1 << 20;
    for(int k = i; k < j; ++k){
        i_k = computeSplit(i, k);
        k_j = computeSplit(k+1, j);
        if(abs(i_k - k_j) < ans) ans = abs(i_k - k_j);
    }
    return ans;
}

int main(){

    int TC, ans;
    scanf(" %d", &TC);
    while(TC--){
        fill(&memo[0][0], &memo[99][99], -1);
        scanf(" %d", &m);
        for(int i = 0; i < m; ++i)
            scanf(" %d", &coins[i]);
        for(int d = 0; d < m; ++d)
            for(int i = 0; i+d < m; ++i)
                computeSplit(i, i+d);

        printf("%d\n", m == 0 ? 0 : computeSplit(0, m-1));
    }

}
