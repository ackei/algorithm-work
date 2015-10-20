#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(){

    char cities[101][5];
    bool nl = false;

    do{
        int scores[100] = {};
        int nc = 1;
        int asg = 0;
        char clr, mat;
        while(scanf("%c/%c,", &clr, &mat) && clr != 'e'){
            if(clr == '#'){
                return 0;
            }
            if(nl){
                printf("\n");
                nl = false;
            }
            switch(clr){
                case 'r':
                    cities[nc][0] = mat;
                    break;
                case 'o':
                    cities[nc][1] = mat;
                    break;
                case 'y':
                    cities[nc][2] = mat;
                    break;
                case 'g':
                    cities[nc][3] = mat;
                    break;
                case 'b':
                    cities[nc][4] = mat;
                    break;
            }
            if(asg == 5){
                ++nc;
                asg = 0;
            } else {
                ++asg;
            }
        }

        for(int i = 1; i < nc; ++i){
            for(int j = 1; j < nc; ++j){
                if(i == j){ continue;}
                int used = 0;
                for(int k = 0; k < 5; ++k){
                    if(cities[i][k] != cities[j][k] && !((1<<k) & used)){
                        for(int m = 0; m < 5; ++m){
                            if(cities[i][k] == cities[j][m]){
                                if(cities[i][m] == cities[j][k]){
                                    used |= (1<<m);
                                }
                                ++scores[i];
                            }
                        }
                    }
                }
            }
        }

        int bestScore = 64;
        int bestIndx = -1;
        for(int i = 1; i < nc; ++i){
            if(scores[i] <= bestScore){
                bestScore = scores[i];
                bestIndx = i;
            }
        }

        if(bestIndx != -1){
            printf("%d", bestIndx);
            nl = true;
        }

    }while(true);

}
