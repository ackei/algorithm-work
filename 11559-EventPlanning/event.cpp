#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<iostream>
using namespace std;

int main(){

    int N, B, H, W, p, a, bestH, bestB;
    vector<string> answers;

    while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
        bestB = 500001;
        while(H--){
            scanf("%d", &p);
            for(int i = 0; i < W; ++i){
                scanf("%d", &a);
                if(a < N){
                    continue;
                } else {
                    if(N * p < bestB && N * p < B){
                        bestB = N * p;
                    }
                }
            }
        }

        answers.push_back((bestB == 500001 ? "stay home" : to_string(bestB)));

    }

    for(int i = 0; i < answers.size(); ++i){
        cout << answers[i] << endl;
    }

}
