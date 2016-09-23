#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int main(){

    int T, N, v, max, c = 1;
    string format = "Case %d: %d";
    const char* fmt = format.c_str();
    vector<string> answers;
    char ans[20];
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        max = -1;
        while(N--){
            scanf("%d", &v);
            if(max < v){
                max = v;
            }
        }
        sprintf(ans, fmt, c++, max);
        answers.push_back(string(ans));
    }

    for(int i = 0; i < answers.size(); ++i){
        cout << answers[i] << endl;
    }

}
