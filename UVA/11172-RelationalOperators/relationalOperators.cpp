#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(){

    int TC, a, b;
    vector<char> answers;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &a, &b);
        char relation = a < b ? '<' : a == b ? '=' : '>';
        answers.push_back(relation);
    }

    for(int i = 0; i < answers.size(); ++i){
        cout << answers[i] << endl;
    }

}
