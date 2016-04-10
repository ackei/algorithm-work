#include<cstdio>
#include<set>
#include<string>
#include<iostream>
using namespace std;

int main(){

    int n, p, m, i, r, c = 1;
    string bestName;
    char name[81], line[81];
    float d, bestScore, bestPrice;
    while(scanf("%d %d", &n, &p) && n && p){
        if(c > 1){
            printf("\n");
        }
        for(i = 0; i < n; ++i){
            scanf(" %[^\n]", line);
        }
        p--;
        scanf("%s", name);
        bestName = string(name);
        scanf("%f %d", &d, &r);
        bestScore = (float)r / n;
        bestPrice = d;
        for(i = 0; i < r; ++i){
            scanf(" %[^\n]", line);
        }
        while(p--){
            scanf("%s", name);
            scanf("%f %d", &d, &r);
            if(bestScore < (float)r / n){
                bestName = string(name);
                bestScore = (float)r / n;
                bestPrice = d;
            } else if(bestScore == (float)r / n){
                if(d < bestPrice){
                    bestName = string(name);
                    bestScore = (float)r / n;
                    bestPrice = d;
                }
            }
            for(i = 0; i < r; ++i){
                scanf(" %[^\n]", line);
            }
        }
        printf("RFP #%d\n%s\n", c++, bestName.c_str());
    }

}
