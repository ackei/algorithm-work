#include<cstdio>
#include<cstring>
using namespace std;

int main(){

    int n, total, tests = 0;
    int matrix[101][101] = {0};
    bool used[101][101][101] = {0};

    while(scanf("%d", &n) != EOF){

        ++tests;
        if(tests > 1){
            printf("\n");
        }
        memset((void*) matrix, 0, (n+1)*101*sizeof(int));
        memset((void*) used, 0, (n+1)*101*101*sizeof(bool));

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                scanf("%d", &matrix[i][j]);
                //printf("%d ", matrix[i][j]);
            }
            //printf("\n");
        }
        //printf("\n");

        total = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                for(int k = 1; k <= n; ++k){
                    if(matrix[i][j] && matrix[j][k] && matrix[k][i]
                       && !used[i][j][k]
                       && ((i < j && j < k) || (i > j && j > k))){
                        used[i][j][k] = true;
                        used[j][k][i] = true;
                        used[k][i][j] = true;
                        printf("%d %d %d\n", i, j, k);
                        ++total;
                    }
                }
            }
        }

        printf("total:%d\n", total);

    }


}
