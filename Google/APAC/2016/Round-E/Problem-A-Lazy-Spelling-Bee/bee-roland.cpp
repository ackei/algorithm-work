#include<cstdio>
#include<cstring>
using namespace std;

typedef unsigned long long int ull;

int len_word;
char word[1<<10];
ull memo[1<<10];
ull mod = 1000000007;

ull bee(int idx){
    if(idx == 0) return 1;
    if(idx == 1) return word[0] == word[1] ? 1 : 4;
    if(memo[idx]) return memo[idx];
    if(word[idx] == word[idx-1]){
        memo[idx] = bee(idx-1);
    } else if (word[idx-2] == word[idx-1]){
        memo[idx] = 4*bee(idx-1);
    } else if (word[idx-2] == word[idx]) {
        memo[idx] = 2*bee(idx-1);
    } else {
        memo[idx] = 3*bee(idx-1);
    }
    memo[idx] = memo[idx] % mod;
    return memo[idx];
}

int main(){

    int T, C=1;
    scanf("%d", &T);
    while(T--){
        memset((void*)&memo[0], 0, (1<<10)*sizeof(ull));
        scanf("%s", &word[0]);
        len_word = strlen(word);
        printf("Case #%d: %llu\n", C++, bee(len_word-1));
    }
}
