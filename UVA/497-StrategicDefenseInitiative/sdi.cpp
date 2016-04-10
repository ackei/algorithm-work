#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;


int main(){
    int TC;
    scanf("%d ", &TC);
    while(TC--){
        int alt, max_hits = 0, max_idx = 0;
        vector<int> missiles;
        vector<int> lis;
        vector<int> point_back;
        string s;
        while(getline(cin, s) && s != ""){
            sscanf(s.c_str(), " %d", &alt);
            missiles.push_back(alt);
        }
        for(int i = 0; i < missiles.size(); ++i){
            lis.push_back(1);
            point_back.push_back(-1);
            for(int k = 0; k < i; ++k)
                if(missiles[k] < missiles[i] && lis[i] < lis[k] + 1){
                    lis[i] = lis[k] + 1;
                    point_back[i] = k;
                }
            if(max_hits < lis[i]){
                max_hits = lis[i];
                max_idx = i;
            }
        }
        printf("Max hits: %d\n", max_hits);
        vector<int> altitudes;
        while(point_back[max_idx] != -1){
            altitudes.push_back(missiles[max_idx]);
            max_idx = point_back[max_idx];
        }
        altitudes.push_back(missiles[max_idx]);
        for(int i = altitudes.size() - 1; 0 <= i; --i)
            printf("%d\n", altitudes[i]);
        if(TC > 0) printf("\n");
    }
}
