#include<cstdio>
using namespace std;

int main(){

    int N, TC = 1;
    while(scanf("%d", &N) && N){
        char secret[N];
        char guess[N];
        char counts[10] = {0}, countsRecord[10] = {0};
        for(int i = 0; i < N; ++i){
            scanf("%hhd", &secret[i]);
            ++counts[secret[i]];
            ++countsRecord[secret[i]];
        }
        printf("Game %d:\n", TC++);
        while(true){
            bool brk = true;
            for(int i = 0; i < N; ++i){
                scanf("%hhd", &guess[i]);
                if(guess[i]) brk = false;
            }
            for(int i = 0; i < 10; ++i){
                counts[i] = countsRecord[i];
                //printf("%hhd", counts[i]);
            }
            //printf("\n");
            if(brk) break;
            int strong = 0, weak = 0;
            for(int i = 0; i < N; ++i){
                if(guess[i] == secret[i]){
                    ++strong;
                    --counts[guess[i]];
                }
            }
            //for(int i = 0; i < 10; ++i) printf("%hhd", counts[i]);
            //printf("\n");
            for(int i = 0; i < N; ++i){
                if(guess[i] != secret[i] && counts[guess[i]]){
                    ++weak; --counts[guess[i]];
                }
            }
            printf("    (%d,%d)\n", strong, weak);
        }
    }

}
