#include<iostream>
#include<algorithm>
using namespace std;

int m, n, gold, heads[20000], knights[20000];

bool slay(){
    gold = 0;
    sort(heads, heads + n);
    sort(knights, knights + m);
    int heads_idx = 0, knights_idx = 0;
    while(heads_idx < n){
        while((knights_idx < m) &&
              (knights[knights_idx] < heads[heads_idx])) ++knights_idx;
        if(knights_idx == m) return false;
        gold += knights[knights_idx++];
        ++heads_idx;
    }
    return true;
}

int main(){
    while(scanf("%d %d", &n, &m), (m && n)){
        for(int i = 0; i < n; ++i) scanf("%d", &heads[i]);
        for(int i = 0; i < m; ++i) scanf("%d", &knights[i]);
        if(slay()) printf("%d\n", gold);
        else printf("%s\n", "Loowater is doomed!");
    }
}
