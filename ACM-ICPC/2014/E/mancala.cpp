#include<cstdio>
#include<iostream>
using namespace std;

char table[2001][81] = {0};

void solve(){
    table[1][0] = 1; table[1][1] = 1;
    int j;
    for(int i = 2; i <= 2000; ++i){
        j = 1;
        while(table[i-1][j] != 0){
            ++j;
        }
        if(j == table[i-1][0] + 1) table[i][0] = j;
        else table[i][0] = table[i-1][0];
        table[i][j] = j;
        for(int k = 1; k < j; ++k) table[i][k] = table[i-1][k] - 1;
        for(int k = j+1; k <= table[i-1][0]; ++k) table[i][k] = table[i-1][k];
    }
}

int main(){
    solve();
    int P, K, N;
    scanf("%d", &P);
    while(P--){
        scanf("%d %d", &K, &N);
        printf("%d %hhd\n", K, table[N][0]);
        int j;
        for(j = 1; j < table[N][0]; ++j){
            printf("%hhd", table[N][j]);
            printf(j % 10 == 0 ? "\n" : " ");
        }
        printf("%hhd\n", table[N][j]);
    }
}
