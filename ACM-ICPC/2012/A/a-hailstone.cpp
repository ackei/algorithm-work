#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int answers[100010];

int largestSeqNum(int n){
    int current, max = current = n;
    while (current > 1){
        if (current < 100010 && answers[current] > 0){
            if (answers[current] > max)
                max = answers[current];
            return max;
        }
        if (current % 2){
            current = current * 3 + 1;    
        }
        else{
            current /= 2;
        }
        if (current > max) max = current;
    }
    return answers[n] = max;
}

int main(){
    int P, t, n;
    memset(answers,0,sizeof answers);
    scanf("%d",&P);
    while (P--){
        scanf("%d %d",&t,&n);
        printf("%d %d\n",t,largestSeqNum(n));
    }
}
