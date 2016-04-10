#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

    int TC, dx, dy, x, y;
    vector<string> answers;
    while(scanf("%d", &TC) && TC){
        scanf("%d %d", &dx, &dy);
        while(TC--){
            scanf("%d %d", &x, &y);
            if(dx == x || dy == y){
                answers.push_back("divisa");
            } else if(x < dx && dy < y){
                answers.push_back("NO");
            } else if(x < dx && dy > y){
                answers.push_back("SO");
            } else if(x > dx && y > dy){
                answers.push_back("NE");
            } else if(x > dx && y < dy){
                answers.push_back("SE");
            }
        }
    }

    for(int i = 0; i < answers.size(); ++i){
        cout << answers[i] << endl;
    }

}
