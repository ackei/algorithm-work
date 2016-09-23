#include<cstdio>
using namespace std;

unsigned long long int cum_matrix[1000][1000];

int main(){

    int N, M;
    unsigned long long acc, l_sum;
    bool prev = false;
    while(scanf(" %d %d", &N, &M) != EOF){
        if(prev) printf("\n");
        else prev = true;
        acc = 0;
        for(int i = N - 1; 0 <= i; --i) for(int j = 0; j < N; ++j){
            scanf("%llu", &cum_matrix[i][j]);
            if(i < N - 1) cum_matrix[i][j] += cum_matrix[i+1][j];
            if(j > 0) cum_matrix[i][j] += cum_matrix[i][j-1];
            if(i < N-1 && j > 0) cum_matrix[i][j] -= cum_matrix[i+1][j-1];
        }
        for(int i = N - M; i >= 0; --i) for(int j = M - 1; j < N; ++j){
            l_sum = cum_matrix[i][j];
            if(i < N - M) l_sum -= cum_matrix[i+M][j];
            if(j > M - 1) l_sum -= cum_matrix[i][j-M];
            if(i < N - M && j > M - 1) l_sum += cum_matrix[i+M][j-M];
            acc += l_sum;
            printf("%llu\n", l_sum);
        }
        printf("%llu\n", acc);
    }

}
