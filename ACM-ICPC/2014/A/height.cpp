#include<cstdio>
using namespace std;

int heights[20];

int main(){
    int P, K, count = 0, temp;
    scanf("%d", &P);
    while(P--){
        scanf("%d", &K);
        for(int i = 0; i < 20; ++i) scanf("%d", &heights[i]);
        count = 0;
        for(int i = 1; i < 20; ++i)
            for(int j = i; j > 0 && heights[j-1] > heights[j]; --j){
                ++count; temp = heights[j]; heights[j] = heights[j-1]; heights[j-1] = temp;
            }
        printf("%d %d\n", K, count);
    }
}
