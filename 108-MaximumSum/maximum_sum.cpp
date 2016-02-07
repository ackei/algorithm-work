#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int A[N][N];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                scanf("%d", &A[i][j]);
                if(i > 0) A[i][j] += A[i-1][j];
                if(j > 0) A[i][j] += A[i][j-1];
                if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
                //cout << "A[" << i << "][" << j << "] = " << A[i][j] << " ";
            }
            //cout << endl;
        }
        int bestMax = -127*100*100, sum;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = i; k < N; ++k)
                    for(int l = j; l < N; ++l){
                        sum = A[k][l];
                        if(i > 0) sum -= A[i-1][l];
                        if(j > 0) sum -= A[k][j-1];
                        if(i > 0 && j > 0) sum += A[i-1][j-1];
                        bestMax = max(bestMax, sum);
                        //if(sum == bestMax) cout << "i: " << i << " j: " << j << " k: " << k << " l: " << l<< endl;
                    }
        printf("%d\n", bestMax);
    }
}
