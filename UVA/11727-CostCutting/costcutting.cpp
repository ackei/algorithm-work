#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int TC, c = 1, sal[3];
    vector<string> answers;
    string fmt = "Case %d: %d";
    const char *format = fmt.c_str();
    char ans[32];
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d", &sal[0], &sal[1], &sal[2]);
        sort(sal, sal + 3);
        sprintf(ans, format, c++, sal[1]);
        answers.push_back(string(ans));
    }

    for(int i = 0; i < answers.size(); ++i){
        cout << answers[i] << endl;
    }

}
