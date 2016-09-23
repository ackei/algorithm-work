#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){

    int TC, m, n;
    char type;
    scanf("%d", &TC);
    //cout << "TC: " << TC << endl;
    while(TC--){
        //cout << "TC: " << TC << endl;
        scanf(" %c %d %d", &type, &m, &n);
        //cout << "type: " << type << endl;
        switch(type){
            case 'r':
            case 'Q':
                printf("%d\n", min(m, n));
                break;
            case 'k':
                printf("%d\n", m * n / 2 + ((m * n % 2 == 1) ? 1 : 0));
                break;
            case 'K':
                printf("%d\n", ((m+1) / 2) * ((n+1) / 2));
                break;
        }
    }

}
