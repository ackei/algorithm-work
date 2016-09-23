#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

int flip(char *S){
    int lenS = strlen(S);
    for(int i = 0; i < lenS; ++i){
        if(S[i] != '+') goto lbl;
    }
    return 0;
    lbl:
    int p = 0;
    if(S[p] == '+'){
        // We have to flip the p-prefix
        while(S[p] == '+') ++p;
    } else {
        p = lenS;
        while(S[p - 1] == '+') --p;
    }
    reverse(S, S + p);
    for(int i = 0; i < p; ++i) S[i] = (S[i] == '+') ? '-' : '+';
    return 1 + flip(S);
}

int main(){

    int T, C = 1;
    char arr[1 << 7], *S = arr;
    scanf("%d", &T);
    while(T--){
        scanf(" %s", S);
        printf("Case #%d: %d\n", C++, flip(S));
    }

}
