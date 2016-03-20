#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int TC, d, i, j, a[21];
unsigned long long k;

int main(){

    scanf("%d\n", &TC);
    while(TC--){

        scanf("%d", &i);
        for(j = 0; j <= i; ++j) scanf("%d", a + j);
        scanf("%d", &d);
        scanf("%d", &k);

        unsigned long long n = (unsigned long long)(ceil(sqrt(0.25 + 2.0/d * k) - 0.5));
        unsigned long long result = a[0];
        unsigned long long mult = 1;
        for(j = 1; j <= i; ++j){
            mult *= n;
            result += mult * a[j];
        }

        printf("%llu\n", result);

    }

}
