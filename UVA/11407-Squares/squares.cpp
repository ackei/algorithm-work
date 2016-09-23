#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

bool perfectSquares[10001] = {false};
int memo[10001] = {0};

int terms(int N){
    if(perfectSquares[N]) return 1;
    if(memo[N]) return memo[N];
    int ans = 10001;
    for(int i = 1; i*i < N; ++i)
        ans = min(ans, 1 + terms(N - i*i));
    memo[N] = ans;
    return ans;
}

int main(){

    for(int i = 1; i <= 100; ++i) perfectSquares[i*i] = true;
    int T, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%d\n", terms(N));
    }

}
