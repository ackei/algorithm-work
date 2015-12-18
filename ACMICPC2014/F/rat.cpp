#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

pair<int, int> traverse(int n, int d){
    int uprights = 0;
    if(n == 1 && d == 1) return make_pair(1, 2);
    if(d == 1) return make_pair(1, 1 + n);
    while(n > d){
        n = n - d;
        ++uprights;
    }
    d = d - n;
    n = d + n;
    for(int i = 0; i < uprights; ++i) d = d + n;
    return make_pair(n, d);
}

int main(){
    int P, K, p, q;
    pair<int, int> ans;
    scanf("%d", &P);
    while(P--){
        scanf("%d %d/%d", &K, &p, &q);
        ans = traverse(p, q);
        printf("%d %d/%d\n", K, ans.first, ans.second);
    }
}
