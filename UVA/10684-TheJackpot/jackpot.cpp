#include<cstdio>
using namespace std;

int main(){

    int N;
    while(scanf("%d", &N) && N){
        int numbers[N];
        for(int i = 0; i < N; ++i) scanf("%d", &numbers[i]);
        int sum = 0, ans = 0;
        for(int i = 0; i < N; ++i){
            sum += numbers[i];
            if(sum < 0) sum = 0;
            if(ans < sum) ans = sum;
        }
        if(ans){ printf("The maximum winning streak is %d.\n", ans); }
        else { printf("Losing streak.\n"); }
    }

    return 0;

}
