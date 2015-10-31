#include<cstdio>
#include<tuple>
#include<map>
#include<cmath>
#include<iostream>
using namespace std;

map<tuple<int, int, int>, int> memo;
int coins[101], m;

int coin(int val_A, int val_B, int coin_no){
    if(coin_no == m)
        return val_A < val_B ? abs(val_B - val_A - coins[coin_no]) :
                               abs(val_A - val_B - coins[coin_no]);
    if(memo.count(make_tuple(val_A, val_B, coin_no)))
        return memo[make_tuple(val_A, val_B, coin_no)];
    int ans = 1 << 20;
    ans = min(coin(val_A + coins[coin_no], val_B, coin_no + 1),
              min(ans, coin(val_A, val_B + coins[coin_no], coin_no + 1)));
    memo.insert(make_pair(make_tuple(val_A, val_B, coin_no), ans));
    return ans;
}

int main(){

    int TC, ans;
    scanf(" %d", &TC);
    while(TC--){
        memo.clear();
        scanf(" %d", &m);
        coins[0] = 0;
        for(int i = 1; i <= m; ++i) scanf(" %d", &coins[i]);
        ans = coin(0, 0, 0);
        printf("%d\n", ans);
    }

}
