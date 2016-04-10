#include<cstdio>
#include<algorithm>
using namespace std;

size_t memo[65][65];

size_t trib(int n, unsigned int back){
    if(n <= 1) return 1;
    if(memo[n][back] != 0) return memo[n][back];
    size_t &ans = memo[n][back] = 1;
    for(int i = 1; i <= back; ++i) ans += trib(n-i, back);
    return ans;
}

int main(){

    int n, back, TC = 1;
    while(scanf("%d %d", &n, &back) && n <= 60 && back <= 60){
        fill(&memo[0][0], &memo[0][0] + 65*65, 0);
        printf("Case %d: %zu\n", TC++, trib(n, back));
    }
    return 0;

}
